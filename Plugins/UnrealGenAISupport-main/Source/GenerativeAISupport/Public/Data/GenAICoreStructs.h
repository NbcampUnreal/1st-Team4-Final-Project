#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GenAICoreStructs.generated.h"

// 공통 메시지 구조체
USTRUCT(BlueprintType)
struct FGenAIMessage
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenAI")
    FString Role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenAI")
    FString Content;
};

// 모든 Provider 옵션의 추상 부모 클래스
UCLASS(Abstract, Blueprintable, EditInlineNew)
class GENERATIVEAISUPPORT_API UGenAIRequestOptions : public UObject
{
    GENERATED_BODY()
};

// 공통 요청 구조체 (옵션 포함)
USTRUCT(BlueprintType)
struct FGenAIChatRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenAI")
    TArray<FGenAIMessage> Messages;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "GenAI")
    TObjectPtr<UGenAIRequestOptions> ProviderOptions = nullptr;
};