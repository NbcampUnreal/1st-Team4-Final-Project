#pragma once

#include "CoreMinimal.h"
#include "AI/BaseAI.h"
#include "Deer.generated.h"

UCLASS()
class EMBER_API ADeer : public ABaseAI
{
	GENERATED_BODY()

public:
	ADeer();
virtual void BeginPlay() override;

	
};
