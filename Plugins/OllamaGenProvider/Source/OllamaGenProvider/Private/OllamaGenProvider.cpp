#pragma once
#include "OllamaGenProvider.h"

void FOllamaGenProviderModule::StartupModule()
{
}

void FOllamaGenProviderModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FOllamaGenProviderModule, OllamaGenProvider) // (이 줄은 가장 아래에 있어야 합니다)