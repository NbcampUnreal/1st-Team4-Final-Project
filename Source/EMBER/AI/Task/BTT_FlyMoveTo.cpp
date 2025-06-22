// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTT_FlyMoveTo.h"
#include "AI/Base/BaseAI.h"
#include "AI/CAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_FlyMoveTo::UBTT_FlyMoveTo()
{
	NodeName = "FlyMoveTo";
	bNotifyTick = true;
	// TargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_FlyMoveTo, TargetActor), AActor::StaticClass());
	//TargetLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_FlyMoveTo, TargetLocationKey));
	//TargetLocationKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_FlyMoveTo, TargetLocationKey), AActor::StaticClass());
}

EBTNodeResult::Type UBTT_FlyMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BaseAI = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn());
	if (!BaseAI) return EBTNodeResult::Failed;
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	FBlackboard::FKey KeyID = BlackboardKey.GetSelectedKeyID();
	if (KeyID == FBlackboard::InvalidKey)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Blackboard Key"));
		return EBTNodeResult::Failed;
	}

	TSubclassOf<UBlackboardKeyType> KeyTypeClass = BlackboardComp->GetKeyType(KeyID);
	if (!KeyTypeClass)
	{
		UE_LOG(LogTemp, Error, TEXT("KeyType is null"));
		return EBTNodeResult::Failed;
	}

	UE_LOG(LogTemp, Warning, TEXT("KeyType: %s"), *KeyTypeClass->GetName());
	
	if (KeyTypeClass == UBlackboardKeyType_Vector::StaticClass())
	{
		 TargetLocation = BlackboardComp->GetValueAsVector(BlackboardKey.SelectedKeyName);
	}
	else if (KeyTypeClass == UBlackboardKeyType_Object::StaticClass())
	{
		TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(BlackboardKey.SelectedKeyName));
		TargetLocation = TargetActor->GetActorLocation();
	}
	else
	{
		UE_LOG(LogTemp,Warning,L"Wrong Type in FlyMoveTO")
	}
	
	CurrentLocation = BaseAI->GetActorLocation();
	FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
	float Speed = BaseAI->GetCharacterMovement()->MaxFlySpeed;
	BaseAI->GetCharacterMovement()->Velocity = Direction * Speed;
	FRotator NewRotation = Direction.Rotation();
	BaseAI->SetActorRotation(NewRotation);

	return EBTNodeResult::InProgress;
}

bool UBTT_FlyMoveTo::IsNearGround()
{
	if (!BaseAI) return false;

	FVector Start = BaseAI->GetActorLocation();
	FVector End = Start - FVector(0, 0, 300.0f); 

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(BaseAI);

	FHitResult Hit;
	bool bHit = BaseAI->GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start,
		End,
		ECC_Visibility,
		Params
	);
	DrawDebugLine(
		BaseAI->GetWorld(),
		Start,
		End,
		bHit ? FColor::Green : FColor::Red, // 맞으면 초록, 아니면 빨강
		false,
		0.1f,
		0,
		2.0f
	);


	return bHit;
}

bool UBTT_FlyMoveTo::IsNearTargetLocation()
{
	CurrentLocation = BaseAI->GetActorLocation();
	float Distance = FVector::Dist(CurrentLocation, TargetLocation);
	UE_LOG(LogTemp, Warning, TEXT("%f"), Distance);

	return Distance <= 100.0f;
}

void UBTT_FlyMoveTo::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (IsNearGround())
	{
		UE_LOG(LogTemp, Warning, TEXT("On Ground"));
		BaseAI->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		BaseAI->GetCharacterMovement()->GravityScale = 1.0f;
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
	if (IsNearTargetLocation())
	{
		UE_LOG(LogTemp, Warning, TEXT("FlyMove Success"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}

}