#include "Modules/ModuleManager.h"

class FOllamaGenProviderModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};