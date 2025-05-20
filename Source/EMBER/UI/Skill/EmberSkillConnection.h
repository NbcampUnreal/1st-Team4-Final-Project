#pragma once
#include "EMBER.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmberSkillConnection.generated.h"

UCLASS()
class EMBER_API UEmberSkillConnection : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const;
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Timer;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UEmberSkillNode* FromNode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UEmberSkillNode* ToNode;
public:
	void SetFromNode(class UEmberSkillNode* Node);
	void SetTargetNode(class UEmberSkillNode* Node);
	void UpdateLineVisual();
};
