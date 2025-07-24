#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RuneSystemComponent.generated.h"

class ARuneItem;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API URuneSystemComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    URuneSystemComponent();

    /** ·é ÀåÂø ½Ãµµ */
    UFUNCTION(BlueprintCallable, Category = "Rune")
    bool EquipRune(ARuneItem* NewRune);

    /** ·é Á¦°Å */
    UFUNCTION(BlueprintCallable, Category = "Rune")
    void RemoveRune(int32 SlotIndex);

    /** ÇöÀç ·é °¡Á®¿À±â */
    UFUNCTION(BlueprintPure, Category = "Rune")
    ARuneItem* GetRune(int32 SlotIndex) const;

protected:
    UPROPERTY(EditAnywhere, Category = "Rune")
    int32 MaxRuneSlots = 3;

    UPROPERTY(VisibleAnywhere, Category = "Rune")
    TArray<TObjectPtr<ARuneItem>> EquippedRunes;
};
