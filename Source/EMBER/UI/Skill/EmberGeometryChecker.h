#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmberGeometryChecker.generated.h"

UCLASS()
class EMBER_API UEmberGeometryChecker : public UObject
{
	GENERATED_BODY()
public:
	static bool IsWidgetGeometryReady(UWidget* Widget)
	{
		if (!Widget) 
			return false;

		const FVector2D Size = Widget->GetCachedGeometry().GetLocalSize();
		return Size.X > 1.f && Size.Y > 1.f;
	}
    static void DelayUntilWidgetReady(UUserWidget* Context, UWidget* Target, TFunction<void()> Callback, int32 MaxRetries = 10)
    {
        if (!Context || !Target || !Callback) return;

        Context->GetWorld()->GetTimerManager().SetTimerForNextTick([=]()
        {
            if (IsWidgetGeometryReady(Target))
            {
                Callback();
            }
            else if (MaxRetries > 0)
            {
                DelayUntilWidgetReady(Context, Target, Callback, MaxRetries - 1);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Geometry not ready after retrying."));
            }
        });
    }
    static void DelayUntilAllWidgetsReady(UUserWidget* Context, const TArray<UWidget*>& Targets, TFunction<void()> Callback, int32 MaxRetries = 10)
    {
        if (!Context || Targets.Num() == 0 || !Callback) return;

        Context->GetWorld()->GetTimerManager().SetTimerForNextTick([=]()
            {
                bool bAllReady = true;
                for (UWidget* Target : Targets)
                {
                    if (!Target || Target->GetCachedGeometry().GetLocalSize().X <= 1.f || Target->GetCachedGeometry().GetLocalSize().Y <= 1.f)
                    {
                        bAllReady = false;
                        break;
                    }
                }

                if (bAllReady)
                {
                    Callback();
                }
                else if (MaxRetries > 0)
                {
                    DelayUntilAllWidgetsReady(Context, Targets, Callback, MaxRetries - 1);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("One or more widgets never became layout-ready."));
                }
            });
    }
    static bool IsWidgetGeometryValid(UWidget* Widget)
    {
        if (!IsValid(Widget)) 
            return false;

        // 내부 Slate가 제거된 경우, 이 호출 자체에서 오류가 날 수 있으므로 예외 보호까지 사용
        bool bSafe = false;
        try
        {
            const FVector2D Size = Widget->GetCachedGeometry().GetLocalSize();
            bSafe = !Size.IsNearlyZero();
        }
        catch (...)
        {
            UE_LOG(LogTemp, Warning, TEXT("Widget geometry was invalid (caught)."));
        }

        return bSafe;
    }
};
