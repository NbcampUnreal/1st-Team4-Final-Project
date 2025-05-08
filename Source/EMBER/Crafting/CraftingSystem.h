#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player/EmberPlayerCharacter.h"
#include "CraftingSystem.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMBER_API UCraftingSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UCraftingSystem();

	UFUNCTION(BlueprintCallable, Category="Crafting")
	void StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName, float ProcessTime);

	// 인벤토리, 주변 상자 재료 찾기
	UFUNCTION(BlueprintCallable, Category = "Crafting")
	TMap<FString, int32> AggregateIngredients(AEmberPlayerCharacter* Player);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crafting")
	UAnimMontage* ProcessingAnimation;

	// 임시
	void AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName);
	
private:
	// 플레이어 주변 상자에서 재료 검색
	TMap<FString, int32> SearchNearChestsIngredients(AEmberPlayerCharacter* Player);
};

