#pragma once

#include "CoreMinimal.h"
#include "AI/Base/PassiveAI.h"
#include "Rabbit.generated.h"


UCLASS()
class EMBER_API ARabbit : public APassiveAI
{
	GENERATED_BODY()

public:
	ARabbit();
	virtual void OnDeath() override;
};