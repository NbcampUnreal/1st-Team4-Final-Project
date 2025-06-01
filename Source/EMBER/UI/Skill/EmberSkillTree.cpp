#include "UI/Skill/EmberSkillTree.h"
#include "EmberSkillConnection.h"
#include "EmberSkillNode.h"
#include "EmberGeometryChecker.h"
#include "Components/CanvasPanel.h"

void UEmberSkillTree::NativeConstruct()
{
    Super::NativeConstruct();

    Init = false;
}

void UEmberSkillTree::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    if (Init == true || bIsDestroyed == true)
        return;

    //UE_LOG(SkillLog, Warning, TEXT("Call Native Tick ⌛"));
    if (IsWidgetReadyForGeometryAccess(this))
    {
        DelayUntilWidgetReady(this, RootPanel, FEmberCallback::CreateLambda([this]()
            {
                UE_LOG(SkillLog, Warning, TEXT("SkillTree WidgetReady진입 ✔️"));
                BuildSkillTree();
            }));
    }
}

void UEmberSkillTree::BuildSkillTree()
{
    UE_LOG(SkillLog, Warning, TEXT("Call BuildSkillTree 📌"));
	TMap<FName, UEmberSkillNode*> NameMap;

    // 1. 모든 노드 수집
    for (UWidget* Widget : RootPanel->GetAllChildren())
    {
        if (UEmberSkillNode* Node = Cast<UEmberSkillNode>(Widget))
        {
            NameMap.Add(Node->NodeName, Node);
        }
    }

    //  BuildConnection
    for (auto& Pair : NameMap)
    {
        UEmberSkillNode* From = Pair.Value;

        for (const FName& TargetName : From->NextNodes)
        {
            if (UEmberSkillNode** ToPtr = NameMap.Find(TargetName))
            {
                UEmberSkillNode* To = *ToPtr;
                From->LinkedNodes.Add(To);

                if (SkillConnectionWidgetClass == nullptr)
                    return;

                if (IsInGameThread())
                {
                    UE_LOG(SkillLog, Warning, TEXT("BuildSkillTree InGameThread 진입 📌"));
                    UEmberSkillConnection* Line = CreateWidget<UEmberSkillConnection>(this, SkillConnectionWidgetClass);
                    Line->FromNode = From;
                    Line->ToNode = To;
                    
                    From->ConnectionLine.Add(Line);
                    From->LinkedNodes.Add(To);

                    RootPanel->AddChild(Line);
                    
                    const TWeakObjectPtr<UEmberSkillConnection> WeakLine = Line;
                    TArray<TWeakObjectPtr<UWidget>> WeakArr = { 
                        Cast<UWidget>(Line),
                        Cast<UWidget>(From),
                        Cast<UWidget>(To)
                    };
                    UE_LOG(SkillLog, Warning, TEXT("BuildSkillTree 진입 📌"));
                    DelayUntilAllWidgetsReady(this, WeakArr, FEmberCallback::CreateLambda([this, WeakLine]()
                    {
                        UE_LOG(SkillLog, Warning, TEXT("BuildSkillTree DelayUntilAllWidgetReady⌛"));
                        if (WeakLine->UpdateLineVisual())
                        {
                            UE_LOG(SkillLog, Warning, TEXT("BuildSkillTree UpdateLineVisual True✔️"));
                        }
                    }));
                }
            }
        }
    }

    Init = true;
}
