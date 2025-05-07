#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_StateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UC_StateComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	UC_StateComponent();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
