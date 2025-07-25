#pragma once

#include "CoreMinimal.h"
#include "EmberWeaponDataAsset.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	FORCEINLINE UWeaponDataAsset* GetWeaponData() { return WeaponAsset; }
private:
	UPROPERTY(EditAnywhere, Category="DataAsset")
	UWeaponDataAsset* WeaponAsset;
public:	
	UWeaponComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void DoAttack();

private:
	ACharacter* OwnerCharacter;
};
