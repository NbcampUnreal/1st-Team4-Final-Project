#include "UI/Skill/EmberSkillNode.h"
#include "EmberSkillConnection.h"

void UEmberSkillNode::NativeConstruct()
{
	Super::NativeConstruct();

	if (NodeID.IsValid() == false)
	{
		NodeID = FGuid::NewGuid();
	}
}

