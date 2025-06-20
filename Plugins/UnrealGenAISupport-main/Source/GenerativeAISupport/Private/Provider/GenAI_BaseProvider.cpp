#include "GenAI_BaseProvider.h"
#include "Json.h"

UGenAI_BaseProvider::GenAI_BaseProvider()
{
    ProviderName = TEXT("deepseek-coder:33b");
}

void UGenAI_BaseProvider::SendPrompt(const FGenAIProviderPromptSettings& Settings)
{
    // API 주소 (Ollama REST)
    FString Url = TEXT("http://localhost:11434/api/generate");
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(Url);
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    // JSON 페이로드
    TSharedPtr<FJsonObject> JsonPayload = MakeShareable(new FJsonObject());
    JsonPayload->SetStringField(TEXT("model"), Settings.ModelName);
    JsonPayload->SetStringField(TEXT("prompt"), Settings.PromptMessage);
    JsonPayload->SetNumberField(TEXT("max_tokens"), Settings.MaxTokens);
    JsonPayload->SetBoolField(TEXT("stream"), Settings.bStreamResponse);

    FString Content;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
    FJsonSerializer::Serialize(JsonPayload.ToSharedRef(), Writer);

    Request->SetContentAsString(Content);

    Request->OnProcessRequestComplete().BindUObject(this, &GenAI_BaseProvider::OnHttpResponseReceived);
    Request->ProcessRequest();
}

void UGenAI_BaseProvider::OnHttpResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    FString Result;
    bool bSuccess = false;
    if (bWasSuccessful && Response.IsValid())
    {
        Result = Response->GetContentAsString();
        bSuccess = true;
    }
    else
    {
        Result = TEXT("Request failed or no response");
    }
    ProcessResponse(Result, bSuccess);
}
