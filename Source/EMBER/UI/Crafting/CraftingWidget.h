#pragma once

#include "../ActivatableWidget.h" 
#include "CraftingWidget.generated.h"

UCLASS()
class EMBER_API UCraftingWidget : public UActivatableWidget
{
	GENERATED_BODY()

public:
	UCraftingWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	virtual void InitializeWidget(const FString& ItemName);

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemNameText;

	virtual void NativeConstruct() override;
};
