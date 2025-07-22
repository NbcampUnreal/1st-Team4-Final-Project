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

protected:
	virtual void BeginPlay() override;

	// Enhanced Input Mapping Context
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UFUNCTION()
	void SetupInputMapping();
};
