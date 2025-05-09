#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

UENUM(BlueprintType)
enum class EAnimalType : uint8
{
	Passive     UMETA(DisplayName = "Passive"),
	Defensive   UMETA(DisplayName = "Defensive"),
	Aggressive  UMETA(DisplayName = "Aggressive")
};

UCLASS()
class EMBER_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	EAnimalType AnimalType;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* PassiveBT;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* DefensiveBT;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* AggressiveBT;

};
