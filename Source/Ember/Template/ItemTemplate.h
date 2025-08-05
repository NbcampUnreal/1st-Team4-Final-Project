#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NiagaraSystem.h"
#include "ItemTemplate.generated.h"

class UNiagaraSystem;

UCLASS(BlueprintType, Blueprintable)

class EMBER_API UItemTemplate : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UTexture2D* Icon;
	// UItemTemplate.h
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visual")
	UStaticMesh* ItemMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 MaxStackSize = 1;

	// 아이템 외형에 사용할 이펙트 (희귀도에 따라 다를 수 있음)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visual")
	UNiagaraSystem* DropEffect;
};
