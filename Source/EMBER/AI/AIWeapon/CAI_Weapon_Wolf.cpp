// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIWeapon/CAI_Weapon_Wolf.h"

ACAI_Weapon_Wolf::ACAI_Weapon_Wolf()
{
}

void ACAI_Weapon_Wolf::DoAction()
{
	if(bEnable == true)
	{
		bEnable = false;
		bExist = true;
		return;
	}
	Super::DoAction();


}

void ACAI_Weapon_Wolf::Begin_DoAction()
{
	Super::Begin_DoAction();

	if(bExist == false)
		return;

	bExist = false;

}

void ACAI_Weapon_Wolf::End_DoAction()
{
	Super::End_DoAction();

	Index = 0;
}
