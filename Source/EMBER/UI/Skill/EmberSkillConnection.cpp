#include "EmberSkillConnection.h"
#include "EmberSkillNode.h"

void UEmberSkillConnection::NativeConstruct()
{
    Super::NativeConstruct();
    bIsVolatile = true;
    Visibility = ESlateVisibility::Visible;
}

void UEmberSkillConnection::NativeDestruct()
{
    Super::NativeDestruct();
}

int32 UEmberSkillConnection::NativePaint(const FPaintArgs& Args, 
    const FGeometry& AllottedGeometry, 
    const FSlateRect& MyCullingRect, 
    FSlateWindowElementList& OutDrawElements, 
    int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
    Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

    UE_LOG(SkillLog, Warning, TEXT("Call Paint ✔️"));
    if (StartPoint == EndPoint)
    {
        UE_LOG(SkillLog, Warning, TEXT("⚠ Line skipped: identical start/end"));
        return LayerId;
    }

    TArray<FVector2D> Points = { StartPoint, EndPoint };

    FSlateDrawElement::MakeLines(
        OutDrawElements,
        LayerId,
        AllottedGeometry.ToPaintGeometry(),
        Points,
        ESlateDrawEffect::None,
        FLinearColor::Red,
        true,
        10.0f
    );

    return LayerId + 1;
}

void UEmberSkillConnection::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

bool UEmberSkillConnection::UpdateLineVisual()
{
    UE_LOG(SkillLog, Warning, TEXT("Call UpdateLineVisual ✔️"));
    if (!FromNode || !ToNode)
    {
        UE_LOG(SkillLog, Warning, TEXT("UpdateLineVisual failed: invalid nodes"));
        return false;
    }

    if (IsWidgetReadyForGeometryAccess() == false)
    {
        UE_LOG(SkillLog, Warning, TEXT("❌Connection Failed : GeomoetryAccess"));
        return false;
    }
    const FVector2D FromLocal = GetCachedGeometry().AbsoluteToLocal(FromNode->GetGeometryAbsolutePosition());
    const FVector2D ToLocal = GetCachedGeometry().AbsoluteToLocal(ToNode->GetGeometryAbsolutePosition());

    StartPoint = FromLocal;
    EndPoint = ToLocal;

    UE_LOG(SkillLog, Warning, TEXT("✅ LineVisual Set: %s → %s"), *StartPoint.ToString(), *EndPoint.ToString());

    Invalidate(EInvalidateWidgetReason::Paint);

    return true;
}
