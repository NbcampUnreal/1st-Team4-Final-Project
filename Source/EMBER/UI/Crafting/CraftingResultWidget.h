#pragma once

#include "CoreMinimal.h"
#include "CraftingWidget.h"
#include "CraftingResultWidget.generated.h"

UCLASS()
class EMBER_API UCraftingResultPreviewWidget : public UCraftingWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void UpdateResultPreview(const FString& PreviewText);

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ResultPreviewText;
    
	UPROPERTY(meta = (BindWidget))
	class UButton* CraftButton;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnCraftButtonClicked();
    
	UFUNCTION(BlueprintImplementableEvent, Category = "Crafting")
	void OnCraftButtonPressed();
};
