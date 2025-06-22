#pragma once

#include "../Data/GenAICoreStructs.h"
#include "OpenAIOptions.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class GENERATIVEAISUPPORT_API UOpenAIOptions : public UGenAIRequestOptions
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OpenAI")
    FString Model = TEXT("gpt-3.5-turbo");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OpenAI")
    float Temperature = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OpenAI")
    int32 MaxTokens = 2048;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OpenAI")
    bool bStream = false;

    // 기타 OpenAI 고유 옵션 추가 가능
};
