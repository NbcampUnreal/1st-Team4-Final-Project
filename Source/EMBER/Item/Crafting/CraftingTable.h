#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CraftingTable.generated.h"

UCLASS()
class EMBER_API ACraftingTable : public AActor
{
	GENERATED_BODY()
    
public: 
	ACraftingTable();

protected:
	virtual void BeginPlay() override;

public: 
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TableMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* InteractionBox;

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	void OnInteract(AActor* Interactor);
};
