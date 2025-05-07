#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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

	float MaxHP;
	float CurrentHP;
	float Speed;
	bool bIsDie;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	float AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	float MoveSpeed;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	UFUNCTION(BlueprintCallable, Category = "AI")
	virtual void Attack(AActor* Target);
	
	UFUNCTION(BlueprintCallable, Category = "AI")
	virtual void OnDeath();

	
};
