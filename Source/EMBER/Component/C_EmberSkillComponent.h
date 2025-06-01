#pragma once

#include "EMBER.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillBase.h"
#include "UI/EmberBaseWidget.h"
#include "GameplayTagsManager.h"
#include "C_EmberSkillComponent.generated.h"

UCLASS(ClassGroup = (Custom)
    , Blueprintable                // 블루프린트로 상속 가능
    , meta = (BlueprintSpawnableComponent)  // 에디터에서 “Add Component” 로 붙일 수 있음
)
class EMBER_API UC_EmberSkillComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UC_EmberSkillComponent();

protected:
	virtual void BeginPlay() override;

protected:
    /** 장착된 스킬 목록 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated)    
    TArray<FSkillNodeData> UnlockedSkills;
public:
    /** 스킬 메뉴로 사용할 UMG Widget 클래스 (블루프린트에서 지정) */
    UPROPERTY(EditDefaultsOnly, Category = "Skill UI")
    TSubclassOf<UEmberBaseWidget> SkillMenuClass;

    /** 생성된 메뉴 인스턴스 */
    UPROPERTY(EditDefaultsOnly, Category = "Skill UI")
    UEmberBaseWidget* SkillMenuWidget = nullptr;
    /** 메뉴가 열려 있는 상태 추적 */
    bool bIsMenuOpen = false;

public:
    /** 스킬 추가 */
    UFUNCTION(BlueprintCallable)
    void AddSkill(class USkillBase* Skill);

    /** 스킬 제거 */
    UFUNCTION(BlueprintCallable)
    void RemoveSkill(class USkillBase* Skill);

    UFUNCTION(BlueprintCallable)
    void ToggleSkillMenu();

    UFUNCTION(BlueprintCallable)
    void TrySkillTreeBuild();
    //UFUNCTION(BlueprintCallable)
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    /** 탭 키 입력 바인딩 */
    void SetupInputBinding();
};
