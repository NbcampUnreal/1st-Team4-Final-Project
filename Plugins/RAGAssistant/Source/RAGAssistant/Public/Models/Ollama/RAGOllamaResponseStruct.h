#pragma once
#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "RAGOllamaResponseStruct.generated.h"

USTRUCT(BlueprintType)
struct FRAGOllamaResponse
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ollama")
    FString Model; // 응답을 생성한 모델 이름

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ollama")
    FString CreatedAt; // 생성 시간

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ollama")
    FString Response; // AI의 실제 응답 텍스트

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ollama")
    bool bDone = false; // 응답 스트림이 완료되었는지 여부 (bStream이 true일 경우 유용)

    // JSON 오브젝트에서 이 Struct로 데이터를 파싱하는 함수
    static FRAGOllamaResponse FromJsonObject(TSharedPtr<FJsonObject> JsonObject)
    {
        FRAGOllamaResponse ResponseData;
        if (JsonObject.IsValid())
        {
            JsonObject->TryGetStringField(TEXT("model"), ResponseData.Model);
            JsonObject->TryGetStringField(TEXT("created_at"), ResponseData.CreatedAt);
            JsonObject->TryGetStringField(TEXT("response"), ResponseData.Response);
            JsonObject->TryGetBoolField(TEXT("done"), ResponseData.bDone);
        }
        return ResponseData;
    }
};