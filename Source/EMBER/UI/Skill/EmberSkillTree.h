#pragma once

#include "CoreMinimal.h"
#include "UI/EmberBaseWidget.h"
#include "EmberSkillConnection.h"
#include "EmberSkillTree.generated.h"

UCLASS()
class EMBER_API UEmberSkillTree : public UEmberBaseWidget
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<class UEmberSkillConnection> SkillConnectionWidgetClass;
    UPROPERTY(meta = (BindWidget))
    class UCanvasPanel* RootPanel;
    bool Init = false;
protected:
    virtual void NativeConstruct();
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
public:
    UFUNCTION(BlueprintCallable)
    void BuildSkillTree();
};
