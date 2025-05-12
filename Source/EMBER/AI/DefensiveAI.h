#pragma once

#include "CoreMinimal.h"
#include "AI/BaseAI.h"
#include "DefensiveAI.generated.h"


UCLASS()
class EMBER_API ADefensiveAI : public ABaseAI
{
	GENERATED_BODY()

public:
	ADefensiveAI();
	virtual void BeginPlay() override;
	virtual void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* AIPerception;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Sight* SightConfig;

};
