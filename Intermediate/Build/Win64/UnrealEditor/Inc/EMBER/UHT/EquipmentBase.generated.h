// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item/Equipment/EquipmentBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EMBER_EquipmentBase_generated_h
#error "EquipmentBase.generated.h already included, missing '#pragma once' in EquipmentBase.h"
#endif
#define EMBER_EquipmentBase_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_EquipmentSlotType); \
	DECLARE_FUNCTION(execOnRep_ItemTemplateID);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEquipmentBase(); \
	friend struct Z_Construct_UClass_AEquipmentBase_Statics; \
public: \
	DECLARE_CLASS(AEquipmentBase, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(AEquipmentBase) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ItemTemplateID=NETFIELD_REP_START, \
		EquipmentSlotType, \
		NETFIELD_REP_END=EquipmentSlotType	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEquipmentBase(AEquipmentBase&&); \
	AEquipmentBase(const AEquipmentBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEquipmentBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEquipmentBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEquipmentBase) \
	NO_API virtual ~AEquipmentBase();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_11_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_14_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class AEquipmentBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_Equipment_EquipmentBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
