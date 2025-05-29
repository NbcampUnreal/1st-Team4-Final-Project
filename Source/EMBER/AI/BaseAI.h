#pragma once

#include "CoreMinimal.h"
#include "EMBER/AI/AI_Interface.h"
#include "EMBER/AI/BaseAIController.h"
#include "GameFramework/Character.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Engine/TargetPoint.h"
#include "BaseAI.generated.h"


UENUM(BlueprintType)
enum class AISoundCategory : uint8
{
	MoveSound UMETA(DisplayName = "Move"),
	AttackSound UMETA(DisplayName = "Attack"),
	HitSound UMETA(DisplayName = "Hit"),
	DeathSound UMETA(DisplayName = "Death")
};

UCLASS()
class EMBER_API ABaseAI : public ACharacter, public IAI_Interface
{
	GENERATED_BODY()

public:
	ABaseAI();
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	                         AActor* DamageCauser) override;

	// AI 기본정보
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Type")
	EAnimalType AnimalType;
	
	// AI State
	UFUNCTION(BlueprintCallable, Category = "AI|State")
	virtual void OnDeath();
	
	UFUNCTION(BlueprintCallable, Category = "AI|State")
	virtual void OnAttack();

	// AI Perception
	UFUNCTION()
	virtual void OnTargetPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus);

	// AI Patrol
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Patrol")
	TArray<ATargetPoint*> PatrolPoint;

	// Getter
	virtual float GetAttackPower() const { return AttackPower; }

	// Setter
	UFUNCTION(BlueprintCallable, Category = "AI|Movement")
	virtual void SetWalkSpeed();

	UFUNCTION(BlueprintCallable, Category = "AI|Movement")
	virtual void SetRunSpeed();
	
	//Interface 함수
	virtual void SetBlackboardBool(FName KeyName, bool bValue) override;
	virtual void SetBlackboardInt(FName KeyName, int value) override;
	virtual void SetBlackboardFloat(FName KeyName, float value) override;
	virtual void SetBlackboardVector(FName KeyName, FVector value) override;
	virtual void SetBlackboardObject(FName KeyName, UObject* object) override;

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
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float RunSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|State")
	bool bIsDie;

	// AI Perception
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Perception")
	UAIPerceptionComponent* AIPerception;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Perception")
	UAISenseConfig_Sight* SightConfig;

	UBlackboardComponent* BlackboardComp;
	
	EAnimalState AnimalState;
};
