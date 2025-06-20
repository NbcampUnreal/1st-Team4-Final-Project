#include "C_RAGHttpActor.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Http.h"

AC_RAGHttpActor::AC_RAGHttpActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AC_RAGHttpActor::SendQueryToAPIServer(const FString& Question)
{
    // 1. JSON 요청 본문 생성
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField("question", Question);

    FString RequestBody;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    // 2. HTTP 요청 생성
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL("http://127.0.0.1:8000/query");
    HttpRequest->SetVerb("POST");
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->SetContentAsString(RequestBody);

    // 3. 응답 처리 함수 바인딩
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &AC_RAGHttpActor::OnHttpResponseReceived);

    // 4. 요청 보내기
    HttpRequest->ProcessRequest();
}

void AC_RAGHttpActor::OnHttpResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    FString AnswerString = TEXT("API 서버와 통신하는 데 실패했습니다. Python 서버가 실행 중인지 확인해주세요.");

    if (bWasSuccessful && Response.IsValid() && Response->GetResponseCode() == 200)
    {
        // 1. 응답을 JSON 객체로 변환
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
        if (FJsonSerializer::Deserialize(Reader, JsonObject))
        {
            // 2. 'answer' 필드 값 추출
            JsonObject->TryGetStringField("answer", AnswerString);
        }
    }

    // 3. 델리게이트를 통해 블루프린트로 답변 전달
    OnResponseReceived.Broadcast(AnswerString);
}