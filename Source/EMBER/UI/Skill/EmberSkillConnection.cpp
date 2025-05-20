#include "EmberSkillConnection.h"

void UEmberSkillConnection::NativeConstruct()
{

}

void UEmberSkillConnection::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

int32 UEmberSkillConnection::NativePaint(
	const FPaintArgs& Args, const FGeometry& AllottedGeometry, 
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, 
	int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	return Super::NativePaint(
		Args,AllottedGeometry,
		MyCullingRect,OutDrawElements,
		LayerId,InWidgetStyle,bParentEnabled);
}

void UEmberSkillConnection::SetFromNode(UEmberSkillNode* Node)
{
	FromNode = Node;
}

void UEmberSkillConnection::SetTargetNode(UEmberSkillNode* Node)
{
	ToNode = Node;
}

void UEmberSkillConnection::UpdateLineVisual()
{
}
