// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EMBER/Item/Fragments/ItemFragment_Equipable_Weapon.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemFragment_Equipable_Weapon() {}

// Begin Cross Module References
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Attachment();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Weapon();
EMBER_API UClass* Z_Construct_UClass_UItemFragment_Equipable_Weapon_NoRegister();
EMBER_API UEnum* Z_Construct_UEnum_EMBER_EWeaponType();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_EMBER();
// End Cross Module References

// Begin Class UItemFragment_Equipable_Weapon
void UItemFragment_Equipable_Weapon::StaticRegisterNativesUItemFragment_Equipable_Weapon()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemFragment_Equipable_Weapon);
UClass* Z_Construct_UClass_UItemFragment_Equipable_Weapon_NoRegister()
{
	return UItemFragment_Equipable_Weapon::StaticClass();
}
struct Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Item/Fragments/ItemFragment_Equipable_Weapon.h" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Weapon.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponType_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Weapon" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Weapon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackSwingSound_MetaData[] = {
		{ "Category", "ItemFragment_Equipable_Weapon" },
		{ "ModuleRelativePath", "Item/Fragments/ItemFragment_Equipable_Weapon.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_WeaponType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_WeaponType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackSwingSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemFragment_Equipable_Weapon>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::NewProp_WeaponType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::NewProp_WeaponType = { "WeaponType", nullptr, (EPropertyFlags)0x0010000000010011, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Weapon, WeaponType), Z_Construct_UEnum_EMBER_EWeaponType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponType_MetaData), NewProp_WeaponType_MetaData) }; // 638223766
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::NewProp_AttackSwingSound = { "AttackSwingSound", nullptr, (EPropertyFlags)0x0114000000010011, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemFragment_Equipable_Weapon, AttackSwingSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackSwingSound_MetaData), NewProp_AttackSwingSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::NewProp_WeaponType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::NewProp_WeaponType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::NewProp_AttackSwingSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UItemFragment_Equipable_Attachment,
	(UObject* (*)())Z_Construct_UPackage__Script_EMBER,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::ClassParams = {
	&UItemFragment_Equipable_Weapon::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::PropPointers),
	0,
	0x003110A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UItemFragment_Equipable_Weapon()
{
	if (!Z_Registration_Info_UClass_UItemFragment_Equipable_Weapon.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemFragment_Equipable_Weapon.OuterSingleton, Z_Construct_UClass_UItemFragment_Equipable_Weapon_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemFragment_Equipable_Weapon.OuterSingleton;
}
template<> EMBER_API UClass* StaticClass<UItemFragment_Equipable_Weapon>()
{
	return UItemFragment_Equipable_Weapon::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UItemFragment_Equipable_Weapon);
UItemFragment_Equipable_Weapon::~UItemFragment_Equipable_Weapon() {}
// End Class UItemFragment_Equipable_Weapon

// Begin Registration
struct Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Weapon_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemFragment_Equipable_Weapon, UItemFragment_Equipable_Weapon::StaticClass, TEXT("UItemFragment_Equipable_Weapon"), &Z_Registration_Info_UClass_UItemFragment_Equipable_Weapon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemFragment_Equipable_Weapon), 4030345421U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Weapon_h_3463933425(TEXT("/Script/EMBER"),
	Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Weapon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PJ_Ember_Source_EMBER_Item_Fragments_ItemFragment_Equipable_Weapon_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
