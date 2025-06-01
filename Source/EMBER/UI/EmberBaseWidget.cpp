#include "EMBER.h"
#include "EmberBaseWidget.h"

void UEmberBaseWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

void UEmberBaseWidget::NativeDestruct()
{
    bIsDestroyed = true;
    Super::NativeDestruct();
}

void UEmberBaseWidget::DelayUntilWidgetReady(TWeakObjectPtr<UUserWidget> Context,
    TWeakObjectPtr<UWidget> Target, FEmberCallback Callback, int32 MaxRetries)
{
    if (Context == nullptr || Target == nullptr || Callback.IsBound() == false) 
        return;

    FTimerHandle DummyHandle;
    Context->GetWorld()->GetTimerManager().SetTimer(DummyHandle,[Context, Target,Callback, MaxRetries]()
        {
            if (IsWidgetReadyForGeometryAccess(Target.Get()))
            {
                //UE_LOG(SkillLog, Warning, TEXT("Call IsWidgetReadyForGeometryAccess✔️"))
                Callback.ExecuteIfBound();
            }
            else if (MaxRetries > 0)
            {
                DelayUntilWidgetReady(Context.Get(), Target.Get(), Callback, MaxRetries - 1);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Geometry not ready after retrying."));
            }
        }, 0.01f, false);
}

void UEmberBaseWidget::DelayUntilAllWidgetsReady(TWeakObjectPtr<UUserWidget> Context,
    const TArray<TWeakObjectPtr<UWidget>>& Targets, FEmberCallback Callback, int32 MaxRetries)
{
    UE_LOG(SkillLog, Warning, TEXT("📌 DelayUntilAllWidgets 진입"));
    if (!Context.IsValid() || !Context->GetWorld() || Targets.Num() == 0 || !Callback.IsBound())
    {
        UE_LOG(SkillLog, Error, TEXT("❌ DelayUntilAllWidgetsSafe 초기조건 실패"));
        return;
    }

    // 1) FTimerDelegate 생성
    FTimerDelegate TimerDel;
    TimerDel.BindLambda([Context, Targets, Callback, MaxRetries]()
        {
            UE_LOG(SkillLog, Warning, TEXT("⏳ NextTick 진입"));  // 이 로그가 찍혀야 합니다.

            if (!Context.IsValid() || !Context->GetWorld())
            {
                UE_LOG(SkillLog, Error, TEXT("❌ Context 파괴됨"));
                return;
            }

            bool bAllReady = true;
            for (auto& WeakW : Targets)
            {
                if (!WeakW.IsValid() || !IsWidgetReadyForGeometryAccess(WeakW.Get()))
                {
                    bAllReady = false;
                    break;
                }
            }

            if (bAllReady)
            {
                UE_LOG(SkillLog, Warning, TEXT("✅ Ready — Callback"));
                Callback.ExecuteIfBound();
            }
            else if (MaxRetries > 0)
            {
                UE_LOG(SkillLog, Warning, TEXT("🔁 재시도 %d회 남음"), MaxRetries - 1);
                UEmberBaseWidget::DelayUntilAllWidgetsReady(Context, Targets, Callback, MaxRetries - 1);
            }
            else
            {
                UE_LOG(SkillLog, Error, TEXT("❌ 재시도 초과"));
            }
        });

    // 2) NextTick 예약
    Context->GetWorld()
        ->GetTimerManager()
        .SetTimerForNextTick(TimerDel);
}

bool UEmberBaseWidget::IsWidgetReadyForGeometryAccess(UWidget* Widget)
{
    if (IsValid(Widget) == false)
    {
        return false;
    }

    //UE_LOG(SkillLog, Warning, TEXT("Viewport: %s, Size: %s"),
    //    Widget->IsInViewport() ? TEXT("✔") : TEXT("❌"),
    //    *Widget->GetCachedGeometry().GetLocalSize().ToString());

    //if (Widget->IsInViewport() == false)
    //{
    //    return false;
    //}

    const FVector2D Size = Widget->GetCachedGeometry().GetLocalSize();

    return !Size.IsNearlyZero();
}

bool UEmberBaseWidget::IsWidgetReadyForGeometryAccess() const
{
    if (IsInViewport() == false)
        return false;

    const FVector2D Size = GetCachedGeometry().GetLocalSize();

    return !Size.IsNearlyZero();
}

FVector2D UEmberBaseWidget::GetGeometryAbsolutePosition() const
{
    if (IsWidgetReadyForGeometryAccess())
        return GetCachedGeometry().GetAbsolutePosition();

    return FVector2D::ZeroVector;
}

bool UEmberBaseWidget::IsDestroyed() const
{
    return bIsDestroyed;
}
