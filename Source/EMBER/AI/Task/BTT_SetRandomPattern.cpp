// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_SetRandomPattern.h"
#include "CAIController.h"
#include "AIComponent/CAIWeaponComponent.h"
#include "AIWeapon/CAI_Weapon_Combo.h"
#include "Base/BaseAI.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTT_SetRandomPattern::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACAIController* AIController = Cast<ACAIController>(OwnerComp.GetOwner());
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	ABaseAI* AI = Cast<ABaseAI>(AIController->GetPawn());
	TObjectPtr<UCAIWeaponComponent> WeaponComponent = AI->FindComponentByClass<UCAIWeaponComponent>();

	int32 RandomRange = WeaponComponent->Weapons[0]->GetAttackDatas().Num();
	int32 RandomInt = FMath::RandRange(0, RandomRange - 1);

	BlackboardComponent->SetValueAsInt("RandomPattern", RandomInt);
	UE_LOG(LogTemp, Error, TEXT("BB_Random Int: %d"), BlackboardComponent->GetValueAsInt("RandomPattern"));
	return EBTNodeResult::Succeeded;
}
