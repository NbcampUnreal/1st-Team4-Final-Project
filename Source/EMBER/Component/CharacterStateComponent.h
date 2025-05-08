#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterStateComponent.generated.h"

UCLASS()
class EMBER_API ACharacterStateComponent : public AActor
{
	GENERATED_BODY()
public:	
	ACharacterStateComponent();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
};
