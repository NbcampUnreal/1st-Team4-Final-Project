#include "CraftingSystem.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "Player/EmberPlayerCharacter.h" 

UCraftingSystem::UCraftingSystem()
{
}

void UCraftingSystem::StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName, float ProcessTime)
{
	if (!Player)
		return;

	if (ProcessingAnimation)
	{
		Player->PlayAnimMontage(ProcessingAnimation);
	}

	FTimerHandle ProcessTimer;
	GetWorld()->GetTimerManager().SetTimer(ProcessTimer, [this, Player, ItemName]()
	{
		// 인벤토리 컴포넌트를 사용해 아이템 추가  
		// if (Player->GetInventoryComponent()) 
		// {
		// 	Player->GetInventoryComponent()->AddItem(ItemName);
		// }
	}, ProcessTime, false);
}
