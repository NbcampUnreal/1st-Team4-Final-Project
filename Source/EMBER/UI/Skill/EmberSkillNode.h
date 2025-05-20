#pragma once
#include "EMBER.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmberSkillConnection.h"
#include "EmberSkillNode.generated.h"

UCLASS()
class EMBER_API UEmberSkillNode : public UUserWidget
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
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PurchaseTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSkillNodeData NodeData;
	// 에디터에서 연결할 다음 노드들
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, FGameplayTag> NextNode;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSubclassOf<UEmberSkillConnection> LineClass;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<UEmberSkillConnection*> LineConnections;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//bool bShowCategoryText;
};
