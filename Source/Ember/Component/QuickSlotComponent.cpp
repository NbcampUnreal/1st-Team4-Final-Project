#include "QuickSlotComponent.h"

UQuickSlotComponent::UQuickSlotComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	QuickSlots.SetNum(MaxSlots); // 슬롯 초기화
}

int32 UQuickSlotComponent::FindSuitableSlot(TSubclassOf<UItemTemplate> ItemClass)
{
	for (int32 i = 0; i < QuickSlots.Num(); ++i)
	{
		if (QuickSlots[i].ItemTemplateClass == ItemClass || QuickSlots[i].ItemTemplateClass == nullptr)
		{
			return i;
		}
	}
	return INDEX_NONE;
}

void UQuickSlotComponent::AddItemToQuickSlot(TSubclassOf<UItemTemplate> ItemClass, int32 Quantity)
{
	if (!ItemClass || Quantity <= 0) return;

	int32 Index = FindSuitableSlot(ItemClass);
	if (Index != INDEX_NONE)
	{
		FQuickSlot& Slot = QuickSlots[Index];
		Slot.ItemTemplateClass = ItemClass;
		Slot.Quantity += Quantity;
		FText DisplayName = ItemClass->GetDefaultObject<UItemTemplate>()->DisplayName;
		//  로그 출력: 어떤 아이템이 몇 번 슬롯에 몇 개 들어갔는지
		UE_LOG(LogTemp, Warning, TEXT("[QuickSlot] Added item: %s x%d to Slot[%d]"),
			*DisplayName.ToString(), Quantity, Index);

		//  UI 갱신 지점 (여기서 위젯에 반영해주는 로직을 호출하세요)
		// UpdateQuickSlotUI(Index); // ← 예시. 실제 UI 함수명에 맞게 수정

		LogQuickSlotState();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[QuickSlot] No available slot found for item: %s"),
			*ItemClass->GetName());
	}
}


void UQuickSlotComponent::UseQuickSlot(int32 Index)
{
	if (!QuickSlots.IsValidIndex(Index)) return;

	FQuickSlot& Slot = QuickSlots[Index];
	if (!Slot.ItemTemplateClass || Slot.Quantity <= 0) return;

	const UItemTemplate* Template = Slot.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
	if (!Template) return;

	// TODO: 효과 적용 (예: 회복)
	UE_LOG(LogTemp, Log, TEXT("Used item: %s"), *Template->DisplayName.ToString());

	Slot.Quantity--;
	if (Slot.Quantity <= 0)
	{
		Slot.ItemTemplateClass = nullptr;
	}
}

const FQuickSlot* UQuickSlotComponent::GetSlot(int32 Index) const
{
	return QuickSlots.IsValidIndex(Index) ? &QuickSlots[Index] : nullptr;
}


void UQuickSlotComponent::LogQuickSlotState() const
{
	UE_LOG(LogTemp, Warning, TEXT("===== Current QuickSlot State ====="));
	for (int32 i = 0; i < QuickSlots.Num(); ++i)
	{
		const FQuickSlot& Slot = QuickSlots[i];

		if (Slot.ItemTemplateClass)
		{
			const UItemTemplate* DefaultItem = Slot.ItemTemplateClass->GetDefaultObject<UItemTemplate>();
			FString ItemName = DefaultItem ? DefaultItem->DisplayName.ToString() : TEXT("Unknown");

			UE_LOG(LogTemp, Warning, TEXT("Slot[%d]: %s x%d"),
				i,
				*ItemName,
				Slot.Quantity);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Slot[%d]: (empty)"), i);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("===================================="));
}

