#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI/BehaviorTree/CBehaviorTreeComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Engine/TargetPoint.h"
#include "BaseAI.generated.h"


class UBehaviorTree;
UENUM(BlueprintType)
enum class AISoundCategory : uint8
{
	MoveSound UMETA(DisplayName = "Move"),
	AttackSound UMETA(DisplayName = "Attack"),
	HitSound UMETA(DisplayName = "Hit"),
	DeathSound UMETA(DisplayName = "Death")
};

UCLASS()
class EMBER_API ABaseAI : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseAI();
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	                         AActor* DamageCauser) override;
	
	// AI State
	UFUNCTION(BlueprintCallable, Category = "AI|State")
	virtual void OnDeath();
	
	UFUNCTION(BlueprintCallable, Category = "AI|State")
	virtual void OnAttack();

	// AI Perception
	//UFUNCTION()
	//virtual void OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus);

	// AI Patrol
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Patrol")
	TArray<ATargetPoint*> PatrolPoint;

	// Getter
	virtual float GetAttackPower() const { return AttackPower; }
	UBehaviorTree* GetBehaviorTree() const;

	// Setter
	UFUNCTION(BlueprintCallable, Category = "AI|Movement")
	virtual void SetWalkSpeed();

	UFUNCTION(BlueprintCallable, Category = "AI|Movement")
	virtual void SetRunSpeed();

	UFUNCTION(BlueprintCallable, Category = "AI|Movement")
	virtual void SetFlySpeed();

protected:
	// AI 기본 정보	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	TObjectPtr<class UMontageSystemComponent> MontageComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	TObjectPtr<class UEquipmentManagerComponent> EquipComponent;
	//TODOS HP 관련 변경 요청
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	TObjectPtr<class UStatusComponent> StatusComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	TObjectPtr<class UC_StateComponent> AIState;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "AI|Behavior")
	TObjectPtr<UCBehaviorTreeComponent> BehaviorTreeComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI|Move")
	TObjectPtr<class UC_CharacterMovementComponent> MoveComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "AI/BehaviorTree")
	UBehaviorTree* BehaviorTree;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float RunSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float FlySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|State")
	bool bIsDie;

	//UAIPerceptionComponent* PerceptionComponent;
	//UBlackboardComponent* BlackboardComp;
};

//TODOS State, Move 컴포넌트 있고어야할듯