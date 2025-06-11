#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFlag.h"
#include "CraftedItemSlotEntryWidget.generated.h"

class UImage;
class UTextBlock;
class UItemTemplate;
class USizeBox;

UCLASS()
class EMBER_API UCraftedItemSlotEntryWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UCraftedItemSlotEntryWidget(const FObjectInitializer& ObjectInitializer);

    /** 외부에서 슬롯의 내용을 설정합니다. */
    UFUNCTION(BlueprintCallable, Category = "CraftedItemSlot")
    void SetSlotData(TSubclassOf<UItemTemplate> InItemTemplateClass, EItemRarity InRarity, int32 InQuantity);

protected:
    /** 슬롯 루트 사이즈 박스 (아이템 크기 조정용) */
    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (BindWidgetOptional))
    TObjectPtr<USizeBox> SizeBox_Root;

    /** 아이템 아이콘 이미지 */
    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (BindWidgetOptional))
    TObjectPtr<UImage> ItemIcon;

    /** 수량 표시 텍스트 */
       /** 아이템 템플릿 클래스 (CDO 사용) */
    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<UItemTemplate> CachedItemTemplateClass;

    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (AllowPrivateAccess = "true"))
    EItemRarity CachedRarity;

    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (AllowPrivateAccess = "true"))
    int32 CachedQuantity;
    UPROPERTY(BlueprintReadOnly, Category = "CraftedItemSlot", meta = (BindWidgetOptional))
    TObjectPtr<UTextBlock> QuantityText;

    /** 슬롯 UI가 갱신된 후 블루프린트에서 후처리를 할 수 있도록 함 */
    UFUNCTION(BlueprintImplementableEvent, Category = "CraftedItemSlot", meta = (DisplayName = "OnDisplayDataUpdated_BP"))
    void K2_OnDisplayDataUpdated();

private:
    /** 위젯 갱신 함수 (내부 전용) */
    void UpdateWidgetAppearance();


};
