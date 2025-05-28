#pragma once

#include "CoreMinimal.h"
#include "CraftingBuilding.h"
#include "CraftingTable.generated.h"

UCLASS()
class EMBER_API ACraftingTable : public ACraftingBuilding
{
	GENERATED_BODY()

public:
	ACraftingTable();

protected:
	virtual void BeginPlay() override;
};
