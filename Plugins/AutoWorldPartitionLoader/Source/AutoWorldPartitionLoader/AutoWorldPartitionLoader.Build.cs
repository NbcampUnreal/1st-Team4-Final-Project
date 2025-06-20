using UnrealBuildTool;

public class AutoWorldPartitionLoader : ModuleRules
{
    public AutoWorldPartitionLoader(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core" });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "EditorSubsystem",
            "EditorFramework",
            "WorldPartitionEditor"
        });
    }
}
