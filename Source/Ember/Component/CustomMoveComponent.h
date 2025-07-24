#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomMoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UCustomMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCustomMoveComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Move(const struct FInputActionValue& Value);
	void Look(const struct FInputActionValue& Value);

private:
	TObjectPtr<ACharacter> OwnerCharacter;
};
