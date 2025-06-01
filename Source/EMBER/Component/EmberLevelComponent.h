#pragma once

#include "EMBER.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EmberLevelComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EMBER_API UEmberLevelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEmberLevelComponent();
protected:
    UPROPERTY()
    TMap<ESkillCategory, class ULevelBase*> CategoryLevel;
public:
    UFUNCTION(BlueprintCallable)
    void AddExpToCategory(ESkillCategory Category, int32 Amount);

    UFUNCTION(BlueprintCallable)
    int32 GetAvailablePoints(ESkillCategory Category) const;

    UFUNCTION(BlueprintCallable)
    bool SpendPoint(ESkillCategory Category);
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
