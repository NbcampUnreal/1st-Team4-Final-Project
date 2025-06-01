#pragma once
#include "EMBER.h"
#include "CoreMinimal.h"
#include "UI/EmberBaseWidget.h"
#include "EmberSkillConnection.generated.h"

UCLASS()
class EMBER_API UEmberSkillConnection : public UEmberBaseWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UEmberSkillNode* FromNode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UEmberSkillNode* ToNode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Timer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D StartPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D EndPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLineColor LineColor;
public:
	UFUNCTION()
	bool UpdateLineVisual();
};
