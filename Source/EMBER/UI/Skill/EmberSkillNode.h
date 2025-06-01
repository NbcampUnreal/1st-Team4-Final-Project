#pragma once
#include "EMBER.h"
#include "CoreMinimal.h"
#include "UI/EmberBaseWidget.h"
#include "EmberSkillConnection.h"
#include "EmberSkillNode.generated.h"

UCLASS()
class EMBER_API UEmberSkillNode : public UEmberBaseWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
public:
	UPROPERTY(meta = (BindWidget))
	class UImage* Icon;
	UPROPERTY(meta = (BindWidget))
	class UImage* LockIcon;
	UPROPERTY(meta = (BindWidget))
	class UImage* UnlockedImage;
	UPROPERTY(meta = (BindWidget))
	class UImage* CheckImage;
protected:
	UPROPERTY()
	FGuid NodeID;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName NodeName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PurchaseTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSkillNodeData NodeData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShowCategoryText;
	// 속한 카테고리
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESkillCategory Category;
	// 선행 조건 (해당 태그가 해제되어야 함)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameplayTag> RequiredSkill;
	// 이 스킬이 열면 활성화 가능한 노드들
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FGameplayTag> UnlockSkill;
	// 실제 태그 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag SkillTag;
	// TargetNode
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> NextNodes; 
	UPROPERTY()
	TArray<UEmberSkillNode*> LinkedNodes;
	// 연결선 노드 (후속 노드 목록)
	UPROPERTY()
	TArray<UEmberSkillConnection*> ConnectionLine;
	// 해제 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUnlocked = false;
};
