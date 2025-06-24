#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h" // UObject를 상속받기 위해 필요
#include "Interfaces/IHttpRequest.h" // HTTP 요청을 위한 헤더
#include "Interfaces/IHttpResponse.h"
#include "Models/Ollama/GenAI_OllamaRequest.h" // ⭐ 방금 만든 요청 Struct
#include "Models/Ollama/GenAI_OllamaResponse.h" // ⭐ 방금 만든 응답 Struct
#include "GenAI_OllamaProvider.generated.h"

// OllamaProvider 클래스는 BaseGenerativeAIProvider를 상속받아 Ollama API와 통신하는 기능을 구현합니다.
// 이 클래스는 Unreal Engine의 UObject를 기반으로 하며, Ollama API와의 상호작용을 위한 메서드를 포함합니다.
// OllamaProvider 클래스는 Unreal Engine의 UObject를 기반으로 하며, Ollama API와의 상호작용을 위한 메서드를 포함합니다.
DECLARE_LOG_CATEGORY_EXTERN(LogGenAI_Ollama, Log, All);

/**
 * @brief Ollama 로컬 LLM과의 통신을 담당하는 Generative AI Provider 클래스입니다.
 * 이 클래스는 기존 플러그인의 다른 Provider (예: OpenAI)와 유사한 방식으로 구현됩니다.
 */
UCLASS(BlueprintType, Blueprintable,Config=Game) // Blueprint에서 사용 가능하도록 설정
class GENERATIVEAISUPPORT_API UGenAI_OllamaProvider : public UObject // ⭐ UObject 상속!
{
    GENERATED_BODY()
public:
    // 비동기식 요청을 위한 델리게이트 선언
    // 이 델리게이트는 요청이 완료되었을 때 AI의 응답 텍스트를 전달합니다.
    DECLARE_DYNAMIC_DELEGATE_OneParam(FOnOllamaCompletionGenerated, const FString&, GeneratedText);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FOnOllamaCompletionFailed, const FString&, ErrorMessage);
public:
    // 생성자: 기본값 초기화
    UGenAI_OllamaProvider();

    // Provider 초기화 함수: 외부에서 Ollama 서버 URL과 모델을 설정할 수 있도록 합니다.
    // InitProvider라는 이름은 기존 플러그인에서 흔히 사용되는 명칭은 아니지만,
    // 우리의 Ollama Provider를 설정하는 명확한 함수로 사용합니다.
    UFUNCTION(BlueprintCallable, Category = "Ollama Settings")
    void InitOllamaProvider(const FString& InOllamaServerUrl, const FString& InDefaultOllamaModel);

    /**
     * @brief AI 텍스트 완성을 요청하는 함수입니다.
     * @param Prompt 사용자 프롬프트 텍스트
     * @param OnCompletionGenerated 성공 시 호출될 델리게이트 (응답 텍스트 반환)
     * @param OnCompletionFailed 실패 시 호출될 델리게이트 (에러 메시지 반환)
     */
    UFUNCTION(BlueprintCallable, Category = "Ollama")
    void GenerateCompletion(
        const FString& Prompt,
        FString& OutResponse, // 동기식 응답을 받을 경우
        FText& OutError,     // 동기식 에러 메시지를 받을 경우
        bool& bSuccess       // 동기식 성공 여부를 받을 경우
    );



    UFUNCTION(BlueprintCallable, Category = "Ollama")
    void GenerateCompletionAsync(
        const FString& Prompt,
        const FOnOllamaCompletionGenerated& OnCompletionGenerated,
        const FOnOllamaCompletionFailed& OnCompletionFailed
    );

    // Ollama 서버 URL과 기본 모델 이름을 언리얼 에디터에서 설정할 수 있도록 UPROPERTY 추가
    UPROPERTY(EditAnywhere, Config, Category = "Ollama Settings")
    FString OllamaServerUrl;

    UPROPERTY(EditAnywhere, Config, Category = "Ollama Settings")
    FString DefaultOllamaModel;

protected:
    // HTTP 요청 완료 시 호출될 콜백 함수 (비동기 요청용)
    void OnGenerateCompletionRequestComplete(
        FHttpRequestPtr Request,
        FHttpResponsePtr Response,
        bool bWasSuccessful,
        FOnOllamaCompletionGenerated OnCompletionGenerated,
        FOnOllamaCompletionFailed OnCompletionFailed
    );

private:
    // 내부적으로 Ollama 서버 URL과 모델 이름을 저장
    FString CurrentOllamaServerUrl;
    FString CurrentDefaultOllamaModel;
};