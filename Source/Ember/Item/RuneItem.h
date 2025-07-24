#pragma once

#include "CoreMinimal.h"
#include "Item/BaseItem.h"
#include "RuneItem.generated.h"

UCLASS()
class EMBER_API ARuneItem : public ABaseItem
{
    GENERATED_BODY()

public:
    ARuneItem();

    virtual void Use(AActor* User) override;

protected:
    UPROPERTY(EditAnywhere, Category = "Rune")
    FName RuneType;

    UPROPERTY(EditAnywhere, Category = "Rune")
    int32 BonusValue;
};
