//#pragma once

//#include "CoreMinimal.h"
//#include "UObject/Interface.h"
//#include "AI_Interface.generated.h"

//UENUM(BlueprintType)
//enum class EAnimalState : uint8
//{
//	Idle UMETA(DisplayName = "Idle"),
//	Eating UMETA(DisplayName = "Eating"),
//	Looking UMETA(DisplayName = "Looking"),
//	Guard UMETA(DisplayName = "Guard"),//경계
//	Near UMETA(DisplayName = "Near"),//
//	Run UMETA(DisplayName = "Running"),//도망
//	Patrol UMETA(DisplayName = "Patrol"),
//	Approach UMETA(DisplayName = "Approach"),
//	Attack UMETA(DisplayName = "Attack"),
//	Hit UMETA(DisplayName = "Hit"),
//	Death UMETA(DisplayName = "Death"),
//	Flying UMETA(DisplayName = "Flying"),//
//};
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAnimalStateChaged, EAnimalState, InPrevType, EAnimalState, InNewType);

//UINTERFACE(MinimalAPI) //건들필요 없는 클래스
//class UAI_Interface : public UInterface
//{
//	GENERATED_BODY()
//};
//
//
//class EMBER_API IAI_Interface
//{
//	GENERATED_BODY()
//
//public:
//	virtual void SetBlackboardBool(FName KeyName, bool bValue) =0;
//	virtual void SetBlackboardInt(FName KeyName, int value) =0;
//	virtual void SetBlackboardFloat(FName KeyName, float value) = 0;
//	virtual void SetBlackboardVector(FName KeyName, FVector value) = 0;
//	virtual void SetBlackboardObject(FName KeyName, UObject* object) = 0;
//
//	//virtual void SetAIStateUpdate();
//};
