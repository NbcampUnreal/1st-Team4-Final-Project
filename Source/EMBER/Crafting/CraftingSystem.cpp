#include "CraftingSystem.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Player/EmberPlayerCharacter.h"

UCraftingSystem::UCraftingSystem()
{
    ProcessingAnimation = nullptr;
}

void UCraftingSystem::StartCrafting(AEmberPlayerCharacter* Player, const FString& ItemName, float ProcessTime)
{
    if (!Player)
    {
        return;
    }

    FTimerHandle MontageTimerHandle;

    if (ProcessingAnimation)
    {
        float MontageDuration = Player->PlayAnimMontage(ProcessingAnimation);

        GetWorld()->GetTimerManager().SetTimer(
            MontageTimerHandle,
            FTimerDelegate::CreateLambda([this, Player]()
            {
                if (Player && ProcessingAnimation)
                {
                    Player->PlayAnimMontage(ProcessingAnimation);
                }
            }),
            MontageDuration, 
            true          
        );
    }

    FTimerHandle ProcessTimer;
    GetWorld()->GetTimerManager().SetTimer(
        ProcessTimer,
        FTimerDelegate::CreateLambda([this, Player, MontageTimerHandle, ItemName]() mutable
        {
            GetWorld()->GetTimerManager().ClearTimer(MontageTimerHandle);

            if (Player && ProcessingAnimation)
            {
                Player->StopAnimMontage(ProcessingAnimation);
            }

            AddItemToInventory(Player, ItemName);
        }),
        ProcessTime, 
        false   
    );
}

TMap<FString, int32> UCraftingSystem::AggregateIngredients(AEmberPlayerCharacter* Player)
{
    TMap<FString, int32> AggregatedIngredients;

    // 플레이어 인벤토리에서 재료 검색
    /*
    if (Player->GetInventoryComponent())
    {
        AggregatedIngredients = Player->GetInventoryComponent()->GetIngredients();
    }
    */

    // 플레이어가 상자 재료 활용 능력을 가진 경우, 주변 상자에서 재료를 검색해 추가
    /*
    if (Player->bHasAbilityToUseNearbyIngredients())
    {
        TMap<FString, int32> NearbyIngredients = SearchNearChestsIngredients(Player);
        for (const auto& Pair : NearbyIngredients)
        {
            int32* FoundQuantity = AggregatedIngredients.Find(Pair.Key);
            if (FoundQuantity)
            {
                *FoundQuantity += Pair.Value;
            }
            else
            {
                AggregatedIngredients.Add(Pair.Key, Pair.Value);
            }
        }
    }
    */

    return AggregatedIngredients;
}

TMap<FString, int32> UCraftingSystem::SearchNearChestsIngredients(AEmberPlayerCharacter* Player)
{
    TMap<FString, int32> FoundIngredients;

    TArray<AActor*> OverlappedActors;
    float SearchRadius = 500.0f;  // 검색 범위 
    FVector PlayerLocation = Player->GetActorLocation();

    TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
    ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

    TArray<AActor*> ActorsToIgnore;
    ActorsToIgnore.Add(Player);

    UKismetSystemLibrary::SphereOverlapActors(
        GetWorld(),
        PlayerLocation,
        SearchRadius,
        ObjectTypes,
        nullptr,        
        ActorsToIgnore,  
        OverlappedActors
    );

    // 검색된 액터들 중에서 "Chest" 태그가 있는 액터들을 처리
    for (AActor* Actor : OverlappedActors)
    {
        if (Actor->ActorHasTag("Chest"))
        {
        }
    }

    return FoundIngredients;
}

void UCraftingSystem::AddItemToInventory(AEmberPlayerCharacter* Player, const FString& ItemName)
{
}
