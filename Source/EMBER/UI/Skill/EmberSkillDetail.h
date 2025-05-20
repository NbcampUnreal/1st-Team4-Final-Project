#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmberSkillDetail.generated.h"

UCLASS()
class EMBER_API UEmberSkillDetail : public UUserWidget
{
	GENERATED_BODY()
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CostText;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TitleText;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DescriptionText;
	UPROPERTY(meta = (BindWidget))
	class UImage* PurchaseIcon;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PurchaseText;
};
