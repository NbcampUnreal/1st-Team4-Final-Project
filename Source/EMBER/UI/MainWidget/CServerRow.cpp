// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget/CServerRow.h"

#include "CMainMenuWidget.h"
#include "Components/Button.h"

void UCServerRow::Setup(UCMainMenuWidget* InParent, uint32 InIndex)
{
	Parent = InParent;
	Index = InIndex;
	RowButton->OnClicked.AddDynamic(this, &UCServerRow::OnClicked);
}

void UCServerRow::OnClicked()
{
	Parent->SelectIndex(Index);
}

void UCServerRow::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (bHeader == true)
		return;
	if (IsHovered() == true)
	{
		if (bSelected == true)
		{
			SetColorAndOpacity(FLinearColor(0.5, 1, 0.5, 1));
		}
		else
		{
			SetColorAndOpacity(FLinearColor(1, 1, 0, 1));
		}
	}
	else
	{
		if (bSelected == true)
		{
			SetColorAndOpacity(FLinearColor(0, 1, 0, 1));
		}
		else
		{
			SetColorAndOpacity(FLinearColor(1, 1, 1, 1));
		}
	}

}
