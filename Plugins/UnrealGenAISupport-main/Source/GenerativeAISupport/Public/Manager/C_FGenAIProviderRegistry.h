#pragma once 

#include "CoreMinimal.h"
#include "UObject/Class.h"

class FGenAIProviderRegistry
{
public:
    static FGenAIProviderRegistry& Get()
    {
        static FGenAIProviderRegistry Instance;
        return Instance;
    }

    void RegisterProvider(const FString& Name, UClass* ProviderClass)
    {
        Providers.Add(Name, ProviderClass);
    }

    UClass* GetProvider(const FString& Name) const
    {
        UClass* Found = *Providers.Find(Name);
        return Found != nullptr ? Found : nullptr;
    }

    TMap<FString, UClass*> GetAllProviders() const { return Providers; }

private:
    TMap<FString, UClass*> Providers;
};