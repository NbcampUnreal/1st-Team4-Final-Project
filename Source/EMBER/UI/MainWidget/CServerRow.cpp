// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget/CServerRow.h"

#include "CMainMenuWidget.h"
#include "Components/Button.h"

void UCServerRow::SetUP(UCMainMenuWidget* InParent, uint32 InIndex)
{
	Parent = InParent;
	Index = InIndex;
	RowButton->OnClicked.AddDynamic(this,&UCServerRow::OnClicked);
}

void UCServerRow::OnClicked()
{
	Parent->SelectIndex(Index);
}
