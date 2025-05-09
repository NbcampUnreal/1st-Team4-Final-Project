// Fill out your copyright notice in the Description page of Project Settings.


#include "CheatEntryWidget.h"

#include "ItemTemplate.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"

UCheatEntryWidget::UCheatEntryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UCheatEntryWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Button_Entry->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonClicked);
}

void UCheatEntryWidget::InitializeUI(ECheatEntryType InCheatEntryType, TSubclassOf<UItemTemplate> InItemTemplateClass, TSoftObjectPtr<UAnimMontage> InAnimMontage)
{
	CheatEntryType = InCheatEntryType;
	
	switch (CheatEntryType)
	{
	case ECheatEntryType::PrimaryWeapon:
	case ECheatEntryType::SecondaryWeapon:
	case ECheatEntryType::Armor:
	case ECheatEntryType::Utility:
		ItemTemplateClass = InItemTemplateClass;
		if (ItemTemplateClass)
		{
			if (UItemTemplate* ItemTemplate = Cast<UItemTemplate>(ItemTemplateClass->GetDefaultObject()))
			{
				Text_Entry->SetText(ItemTemplate->DisplayName);
				Image_Entry->SetBrushFromTexture(ItemTemplate->IconTexture, true);
			}
		}
		break;
	}
}

void UCheatEntryWidget::OnButtonClicked()
{
	
}
