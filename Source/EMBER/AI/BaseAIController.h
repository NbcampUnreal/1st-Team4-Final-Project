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

	// 블랙보드 데이터 (에디터에서 설정)
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBlackboardData* BlackboardAsset;

	// 블랙보드 컴포넌트 (UseBlackboard()를 통해 참조)
	UPROPERTY(VisibleAnywhere, Category = "AI")
	UBlackboardComponent* BlackboardComp;
	
	EAnimalType AnimalType;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* PassiveBT;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* DefensiveBT;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* AggressiveBT;

	UBehaviorTree* CurrentBT;
};
