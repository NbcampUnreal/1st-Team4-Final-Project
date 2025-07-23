#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UCLASS()
class EMBER_API ABaseItem : public AActor
{
	GENERATED_BODY()

public:
	ABaseItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	/** 아이템 메시 (외형) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
	UStaticMeshComponent* ItemMesh;

	/** 아이템 이름 (디버그/로그용) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemName;

	/** 아이템 ID 또는 타입 구분용 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 ItemID;

	/** 상호작용 함수 */
	UFUNCTION(BlueprintCallable, Category = "Item")
	virtual void Interact(AActor* InteractingActor);

	/** 아이템 삭제 */
	UFUNCTION(BlueprintCallable, Category = "Item")
	void DestroyItem();
};
