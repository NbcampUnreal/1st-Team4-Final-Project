#pragma once

#include "CoreMinimal.h"
#include "Provider/GenAI_BaseProvider.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "GenAI_DeepseekProvider.generated.h"


UCLASS(Blueprintable)
class OLLAMAGENPROVIDER_API UGenAI_DeepseekProvider
{
    GENERATED_BODY()

public:
    UGenAI_DeepseekProvider();

    virtual void SendPrompt(const FGenAIProviderPromptSettings& Settings) override;

private:
    void OnHttpResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // 요청 정보 임시 저장 (딥시크 REST 파라미터)
    FString CachedPrompt;
};

