#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmberSkillConnection.h"
#include "EmberSkillTree.generated.h"

UCLASS()
class EMBER_API UEmberSkillTree : public UUserWidget
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<class UEmberSkillConnection> SkillConnectionWidgetClass;

public:
    UFUNCTION(BlueprintCallable)
    void BuildSkillTree();
};
