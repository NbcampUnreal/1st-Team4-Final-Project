#include "Manager/C_FGenAIProviderRegistry.h"
#include "UObject/Class.h"
#include "GenerativeAISupport.h"

#define LOCTEXT_NAMESPACE "FGenerativeAISupportModule"

FGenerativeAISupportModule::FGenerativeAISupportModule()
{
	// Constructor initialization ensures proper state
}

void FGenerativeAISupportModule::StartupModule()
{
    FGenAIProviderRegistry::Get().RegisterProvider(
        TEXT("DeepSeek"),
        UGenAI_DeepseekProvider::StaticClass()
    );
	UE_LOG(LogTemp, Log, TEXT("FGenerativeAISupportModule::StartupModule called"));
}

void FGenerativeAISupportModule::ShutdownModule()
{
	// Runtime module cleanup if needed
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenerativeAISupportModule, GenerativeAISupport)