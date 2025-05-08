#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player/EmberPlayerCharacter.h"
#include "CraftingSystem.generated.h"

class AEmberPlayerCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMBER_API UCraftingSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UCraftingSystem();

	UFUNCTION(BlueprintCallable, Category="Crafting")
	void StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName, float ProcessTime);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crafting")
	UAnimMontage* ProcessingAnimation;

	void AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName);
};
