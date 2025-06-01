#include "Component/C_EmberSkillComponent.h"
#include "SkillBase.h"
#include "Skill/Manager/C_EmberSkillManager.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"

UC_EmberSkillComponent::UC_EmberSkillComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UC_EmberSkillComponent::BeginPlay()
{
	Super::BeginPlay();
    SetupInputBinding();
    // 메뉴 위젯만 생성해 두고, 화면에는 아직 추가하지 않습니다.
    if (SkillMenuClass && GetWorld())
    {
        if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
        {
            SkillMenuWidget = CreateWidget<UEmberBaseWidget>(PC, SkillMenuClass);
        }
    }
}

void UC_EmberSkillComponent::AddSkill(USkillBase* Skill)
{
    //UnlockedSkills.AddUnique(Skill->GetSkillTag());
    //if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
    //{
    //    Skill->ApplySkill(Character);
    //}
}

void UC_EmberSkillComponent::RemoveSkill(USkillBase* Skill)
{
    //if (EquippedSkills.Remove(Skill->GetSkillTag()) > 0)
    //{
    //    if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
    //    {
    //        Skill->RemoveSkill(Character);
    //    }
    //}
}

void UC_EmberSkillComponent::ToggleSkillMenu()
{
    if (!SkillMenuWidget || !GetWorld())
    {
        UE_LOG(SkillLog, Warning, TEXT("[EmberSkillComponent] SkillMenuWidget is null"));
        return;
    }

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (!PC)
        return;

    if (bIsMenuOpen)
    {
        // ─── 메뉴 닫기 ─────────────────────────────────
        SkillMenuWidget->RemoveFromParent();
        bIsMenuOpen = false;

        // 입력 모드: 게임 전용
        FInputModeGameOnly GameInput;
        PC->SetInputMode(GameInput);
        PC->bShowMouseCursor = false;

        // 일시정지 해제
        PC->SetPause(false);
    }
    else
    {
        // ─── 메뉴 열기 ─────────────────────────────────
        SkillMenuWidget->AddToViewport( /* ZOrder = */ 100);
        bIsMenuOpen = true;

        // 입력 모드: 게임 + UI
        FInputModeGameAndUI UIInput;
        UIInput.SetWidgetToFocus(SkillMenuWidget->TakeWidget());
        UIInput.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        PC->SetInputMode(UIInput);
        PC->bShowMouseCursor = true;

        // 게임 일시정지
        PC->SetPause(true);

        // Geometry 준비를 기다리기
        TArray<TWeakObjectPtr<UWidget>> Targets;
        // 예: SkillMenuWidget 안에 UWidget* SkillTreeRoot 가 있다고 가정
        if (UWidget* TreeRoot = SkillMenuWidget->GetWidgetFromName(TEXT("SkillTreeRoot")))
        {
            Targets.Add(TreeRoot);
        }

        // C++ DelayUntilAllWidgetsReady 호출
        FEmberCallback ReadyCb = FEmberCallback::CreateUObject(this, &UC_EmberSkillComponent::TrySkillTreeBuild);
        SkillMenuWidget->DelayUntilAllWidgetsReady(
            TWeakObjectPtr<UUserWidget>(SkillMenuWidget),
            Targets,
            ReadyCb,
            /*MaxRetries=*/ 20
        );
    }
}

void UC_EmberSkillComponent::TrySkillTreeBuild()
{
    
    UE_LOG(SkillLog, Log, TEXT("[EmberSkillComponent] ⌛SkillTree Geometry 준비 완료"));

}

void UC_EmberSkillComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UC_EmberSkillComponent::SetupInputBinding()
{
    if (APlayerController* PC = Cast<APlayerController>(GetOwner()->GetInstigatorController()))
    {
        // 프로젝트 세팅 > Input > Action Mappings 에 "ToggleSkillMenu" 를 등록하세요.
        if (UInputComponent* IC = PC->InputComponent)
        {
            IC->BindAction("ToggleSkillMenu", IE_Pressed, this, &UC_EmberSkillComponent::ToggleSkillMenu);
        }
    }
}
