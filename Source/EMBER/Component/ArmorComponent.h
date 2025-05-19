#pragma once
#include "CoreMinimal.h"
#include "GameFlag.h"
#include "Components/ActorComponent.h"
#include "ArmorComponent.generated.h"

// 아머 데이터를 저장할 구조체 정의
USTRUCT()
struct FArmorData
{
    GENERATED_BODY()
public:
    UPROPERTY()
    EArmorType ArmorType;

    UPROPERTY()
    int32 ItemTemplateID;

    UPROPERTY()
    FString MeshPath;

    FArmorData() : ArmorType(EArmorType::Count), ItemTemplateID(0), MeshPath("") {}

    FArmorData(EArmorType InType, int32 InID, const FString& InPath)
        : ArmorType(InType), ItemTemplateID(InID), MeshPath(InPath) {
    }
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EMBER_API UArmorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UArmorComponent();
protected:
    virtual void BeginPlay() override;
public:
    void DetermineEquip(class UItemFragment_Equipable_Armor* ArmorFragment, int32 NewItemTemplateID);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    void InitializeArmorForLateJoiners();

public:
	UFUNCTION(NetMulticast, Reliable)
    void MulticastInitializeArmor();

private:
    UFUNCTION(Reliable, Server)
    void EquipORUnEquip(USkeletalMesh* Mesh, EArmorType ArmorType, int32 ItemTemplateID);


    // OnRep 콜백 함수 선언
    UFUNCTION()
    void OnRep_ArmorDataArray();

private:
    // 클라이언트에서 사용할 시각적 업데이트 함수
    void UpdateArmorVisuals();

    // 아머 데이터 배열 관리 헬퍼 함수
    void AddOrUpdateArmorData(EArmorType ArmorType, int32 ItemTemplateID, const FString& MeshPath);
    void RemoveArmorData(EArmorType ArmorType);
    FArmorData* FindArmorData(EArmorType ArmorType);
    FString ArmorTypeName(EArmorType& ArmorType);

    // 소유 액터의 권한을 확인하는 헬퍼 함수
    bool HasOwnerAuthority() const;


private:
    // 리플리케이션될 변수들 - TMap 대신 TArray 사용
    UPROPERTY(ReplicatedUsing = OnRep_ArmorDataArray)
    TArray<FArmorData> ArmorDataArray;
private:
    ACharacter* OwnerCharacter;
    TMap<USkeletalMeshComponent*, TMap<EArmorType, int32>> AttachArmors;
};