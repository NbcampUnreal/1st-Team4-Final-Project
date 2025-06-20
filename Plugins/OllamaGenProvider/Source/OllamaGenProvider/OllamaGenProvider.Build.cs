using UnrealBuildTool;

public class OllamaGenProvider : ModuleRules
{
    public OllamaGenProvider(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
            "GenerativeAISupport",
            "HTTP",
            "Json",
            "JsonUtilities"
        });
    }
}
