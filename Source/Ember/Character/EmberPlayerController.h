#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EmberPlayerController.generated.h"

class UInputMappingContext;

/**
 * 플레이어 컨트롤러 - 입력 매핑 컨텍스트 설정용
 */
UCLASS()
class EMBER_API AEmberPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	// Enhanced Input Mapping Context
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr< UInputAction> LookAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr< UInputAction> JumpAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* AttackAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* SprintAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* InteractAction;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void SetupInputMapping();


};
