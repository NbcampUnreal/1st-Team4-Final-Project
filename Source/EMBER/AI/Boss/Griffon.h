#pragma once

#include "CoreMinimal.h"
#include "AI/Base/PassiveAI.h"
#include "Griffon.generated.h"

UCLASS()
class EMBER_API AGriffon : public APassiveAI
{
	GENERATED_BODY()

public:
	AGriffon();
	virtual void BeginPlay() override;
	// virtual void Tick(float DeltaTime) override;

	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};
