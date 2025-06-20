#pragma once

#include "CoreMinimal.h"
#include "GenAICoreStructs.generated.h"

USTRUCT(BlueprintType)
struct UNREALGENAISUPPORT_API FGenAIMessage
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenAI")
    FString Role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenAI")
    FString Content;
};