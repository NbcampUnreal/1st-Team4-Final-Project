#pragma once

#include "EMBER.h"
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "C_SG_EmberSave.generated.h"

UCLASS()
class EMBER_API UC_SG_EmberSave : public USaveGame
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite)
	TArray<FGameplayTag> SavedTags;
};
