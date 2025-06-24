#include "Provider/RAGOllamaProvider.h"
#include "HttpModule.h" // HTTP 요청을 위해 필요
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h" // IHttpResponse에서 HTTP 상태 코드와 내용 가져오기
#include "Serialization/JsonSerializer.h" // JSON 직렬화/역직렬화를 위해 필요
#include "Dom/JsonObject.h" // FJsonObject 사용을 위해 필요

// 로그 카테고리 정의
DEFINE_LOG_CATEGORY(LogGenAI_Ollama);

URAGOllamaProvider::URAGOllamaProvider()
{
    // 생성자에서 Ollama 서버의 기본 URL과 모델 이름을 설정합니다.
    // 이 값들은 언리얼 에디터의 프로젝트 세팅에서 변경할 수 있습니다.
    OllamaServerUrl = TEXT("http://localhost:11434"); // Ollama 기본 URL
    DefaultOllamaModel = TEXT("deepseek-coder:latest"); // 사용할 Deepseek 모델 이름 (예시)
}

// InitOllamaProvider 함수 구현
void URAGOllamaProvider::InitOllamaProvider(const FString& InOllamaServerUrl, const FString& InDefaultOllamaModel)
{
    // 외부에서 전달된 값으로 내부 멤버 변수를 업데이트합니다.
    // 만약 전달된 값이 비어있으면, UPROPERTY로 설정된 기본값을 사용합니다.
    CurrentOllamaServerUrl = InOllamaServerUrl.IsEmpty() ? OllamaServerUrl : InOllamaServerUrl;
    CurrentDefaultOllamaModel = InDefaultOllamaModel.IsEmpty() ? DefaultOllamaModel : InDefaultOllamaModel;

    UE_LOG(LogGenAI_Ollama, Log, TEXT("Ollama Provider Initialized. Server URL: %s, Model: %s"), *CurrentOllamaServerUrl, *CurrentDefaultOllamaModel);
}

// GenerateCompletionAsync 함수 구현 (비동기식 - 권장!)
void URAGOllamaProvider::GenerateCompletionAsync(
    const FString& Prompt,
    FOnOllamaCompletionGenerated OnCompletionGenerated,
    FOnOllamaCompletionFailed OnCompletionFailed
)
{
    UE_LOG(LogGenAI_Ollama, Log, TEXT("Async Ollama Completion requested. Prompt: %s"), *Prompt);

    // Ollama 서버 URL과 모델이 설정되어 있는지 확인
    if (CurrentOllamaServerUrl.IsEmpty() || CurrentDefaultOllamaModel.IsEmpty())
    {
        FString ErrorMsg = TEXT("Ollama Provider is not initialized. Please call InitOllamaProvider first or set values in Project Settings.");
        UE_LOG(LogGenAI_Ollama, Error, TEXT("%s"), *ErrorMsg);
        OnCompletionFailed.ExecuteIfBound(ErrorMsg);
        return;
    }

    // 1. HTTP 요청 객체 생성
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

    // 2. 요청 URL 설정 (Ollama의 /api/generate 엔드포인트)
    HttpRequest->SetURL(FString::Printf(TEXT("%s/api/generate"), *CurrentOllamaServerUrl));
    HttpRequest->SetVerb(TEXT("POST")); // POST 메소드 사용
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json")); // JSON 형식으로 데이터 전송을 알림

    // 3. 요청 데이터 (JSON) 구성
	FRAGOllamaRequest OllamaRequestData; // FGenAI_OllamaRequest 구조체 인스턴스 생성
    OllamaRequestData.Model = CurrentDefaultOllamaModel; // 설정된 기본 모델 사용
    OllamaRequestData.Prompt = Prompt;
    OllamaRequestData.bStream = false; // 일단은 스트리밍 없이 단일 응답으로 시작

    FString RequestBody;
    TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&RequestBody);
    // 우리가 만든 FGenAI_OllamaRequest Struct를 JsonObject로 변환하여 JSON 문자열로 직렬화
    FJsonSerializer::Serialize(OllamaRequestData.ToJsonObject().ToSharedRef(), JsonWriter);
    JsonWriter->Close(); // JsonWriter 닫기 (중요!)

    HttpRequest->SetContentAsString(RequestBody);

    // 4. 응답 처리 콜백 함수 설정
    // BindUObject를 사용하여 UObject의 멤버 함수를 델리게이트에 바인딩
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &URAGOllamaProvider::OnGenerateCompletionRequestComplete, OnCompletionGenerated, OnCompletionFailed);

    // 5. HTTP 요청 전송
    HttpRequest->ProcessRequest();
}

// OnGenerateCompletionRequestComplete 함수 구현 (콜백)
void URAGOllamaProvider::OnGenerateCompletionRequestComplete(
    FHttpRequestPtr Request,
    FHttpResponsePtr Response,
    bool bWasSuccessful, // 이 변수가 네트워크 요청 성공/실패 여부를 알려줘요!
    FOnOllamaCompletionGenerated OnCompletionGenerated,
    FOnOllamaCompletionFailed OnCompletionFailed
)
{
    // bWasSuccessful이 true이고 응답이 유효한 경우
    if (bWasSuccessful && Response.IsValid())
    {
        int32 ResponseCode = Response->GetResponseCode();
        if (ResponseCode >= 200 && ResponseCode < 300) // HTTP 상태 코드가 200번대(성공)인지 확인
        {
            FString ResponseBody = Response->GetContentAsString();
            UE_LOG(LogGenAI_Ollama, Log, TEXT("Ollama Response received (Code: %d): %s"), ResponseCode, *ResponseBody);

            TSharedPtr<FJsonObject> JsonObject;
            TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseBody);

            // JSON 응답을 파싱
            if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
            {
				FRAGOllamaResponse OllamaResponseData = FRAGOllamaResponse::FromJsonObject(JsonObject); // OllamaResponseData 구조체로 JSON 데이터를 역직렬화
                // 성공 델리게이트 호출, AI의 응답 텍스트를 전달
                OnCompletionGenerated.ExecuteIfBound(OllamaResponseData.Response);
            }
            else
            {
                // JSON 파싱 실패
                FString ErrorMessage = FString::Printf(TEXT("Failed to parse Ollama JSON response. Response body: %s"), *ResponseBody);
                UE_LOG(LogGenAI_Ollama, Error, TEXT("%s"), *ErrorMessage);
                OnCompletionFailed.ExecuteIfBound(ErrorMessage);
            }
        }
        else // HTTP 상태 코드가 200번대가 아닌 경우 (예: 400 Bad Request, 500 Internal Server Error 등)
        {
            FString ErrorMessage = FString::Printf(TEXT("HTTP Error: %d - %s"), ResponseCode, *Response->GetContentAsString());
            UE_LOG(LogGenAI_Ollama, Error, TEXT("%s"), *ErrorMessage);
            OnCompletionFailed.ExecuteIfBound(ErrorMessage);
        }
    }
    else // 네트워크 요청 자체(bWasSuccessful)가 실패했거나 응답 객체가 유효하지 않은 경우
    {
        FString ErrorMessage = TEXT("Ollama HTTP Request Failed: Network issue or invalid response.");
        // Request->GetErrorString() 같은 구체적인 오류 문자열은 IHttpRequest 인터페이스에 없습니다.
        // 이 경우, 네트워크 연결 상태나 Ollama 서버의 구동 여부를 직접 확인해야 합니다.
        UE_LOG(LogGenAI_Ollama, Error, TEXT("%s"), *ErrorMessage);
        OnCompletionFailed.ExecuteIfBound(ErrorMessage);
    }
}