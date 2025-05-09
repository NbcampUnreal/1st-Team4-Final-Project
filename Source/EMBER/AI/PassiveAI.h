#pragma once

#include "CoreMinimal.h"
#include "AI/BaseAI.h"
#include "PassiveAI.generated.h"

UCLASS()
class EMBER_API APassiveAI : public ABaseAI
{
	GENERATED_BODY()

public:
	APassiveAI();
	virtual void BeginPlay() override;

	virtual void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors) override;

	UFUNCTION()
	void OnRunPerceptionUpdate(const TArray<AActor*>& UpdatedActors);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Sight* RunSightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* RunPerception;
};
