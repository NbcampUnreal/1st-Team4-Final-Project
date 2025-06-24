#pragma once
#include "CoreMinimal.h"
#include "Dom/JsonObject.h" // JSON 오브젝트 사용을 위해 필요
#include "GenAI_OllamaRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FGenAI_OllamaRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ollama")
    FString Model; // 사용할 Ollama 모델 이름 (예: "deepseek-coder:latest")

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ollama")
    FString Prompt; // AI에게 보낼 텍스트 프롬프트

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ollama")
    bool bStream = false; // 스트리밍 응답을 받을 것인지 (초기에는 false로 시작하는 것을 추천)

    // 이 Struct를 JSON 오브젝트로 변환하는 함수
    TSharedPtr<FJsonObject> ToJsonObject() const
    {
        TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
        JsonObject->SetStringField(TEXT("model"), Model);
        JsonObject->SetStringField(TEXT("prompt"), Prompt);
        JsonObject->SetBoolField(TEXT("stream"), bStream);
        return JsonObject;
    }
};