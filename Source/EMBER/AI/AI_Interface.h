#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AI_Interface.generated.h"

UENUM(BlueprintType)
enum class EAnimalState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Eat UMETA(DisplayName = "Eat"),
	Guard UMETA(DisplayName = "Guard"),
	Run UMETA(DisplayName = "Run"),
	Attack UMETA(DisplayName = "Attack"),
	Death UMETA(DisplayName = "Death"),
	Hit UMETA(DisplayName = "Hit"),
};

UINTERFACE(MinimalAPI)
class UAI_Interface : public UInterface
{
	GENERATED_BODY()
};


class EMBER_API IAI_Interface
{
	GENERATED_BODY()

public:
	// virtual void SetBlackboardBool(FName KeyName, bool bValue) =0;
	// virtual void SetBlackboardInt(FName KeyName, int value) =0;
	// virtual void SetBlackboardFloat(FName KeyName, float value);
	// virtual void SetBlackboardString(FName KeyName, FString value);
	// virtual void SetBlackboardObject(FName KeyName, UObject* object);

	
	//virtual void SetAIStateUpdate();

}; 
