#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EMBER/AI/BaseAIController.h"
#include "Engine/TargetPoint.h"
#include "BaseAI.generated.h"


UENUM(BlueprintType)
enum class AISoundCategory : uint8
{
	MoveSound    UMETA(DisplayName = "Move"),
	AttackSound  UMETA(DisplayName = "Attack"),
	HitSound     UMETA(DisplayName = "Hit"),
	DeathSound   UMETA(DisplayName = "Death")
};

UCLASS()
class EMBER_API ABaseAI : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseAI();
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// AI 기본정보
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Type")
	EAnimalType AnimalType;
	
	// AI Animation
	UFUNCTION(BlueprintCallable, Category = "AI|Animation")
	virtual void PlayAttackAnimation();

	// AI State
	UFUNCTION(BlueprintCallable, Category = "AI|State")
	virtual void OnDeath();

	// AI Perception
	UFUNCTION()
	virtual void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	// AI Patrol
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Patrol")
	TArray<ATargetPoint*> PatrolPoint;

	// Getter
	virtual float GetAttackPower() const { return AttackPower; }

protected:
	// AI 기본 정보
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Stat")
	float AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|State")
	bool bIsDie;

	// AI Perception
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI|Perception")
	UAIPerceptionComponent* AIPerception;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Perception")
	UAISenseConfig_Sight* SightConfig;
};