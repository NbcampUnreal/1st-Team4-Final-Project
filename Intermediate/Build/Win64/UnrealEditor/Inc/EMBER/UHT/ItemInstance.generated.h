// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item/ItemInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Net/Core/PushModel/PushModelMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EItemRarity : uint8;
#ifdef EMBER_ItemInstance_generated_h
#error "ItemInstance.generated.h already included, missing '#pragma once' in ItemInstance.h"
#endif
#define EMBER_ItemInstance_generated_h

#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetItemRarity); \
	DECLARE_FUNCTION(execGetItemTemplateID);


#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUItemInstance(); \
	friend struct Z_Construct_UClass_UItemInstance_Statics; \
public: \
	DECLARE_CLASS(UItemInstance, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UItemInstance) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ItemTemplateID=NETFIELD_REP_START, \
		ItemRarity, \
		NETFIELD_REP_END=ItemRarity	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override; \
private: \
	REPLICATED_BASE_CLASS(UItemInstance) \
public:


#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UItemInstance(UItemInstance&&); \
	UItemInstance(const UItemInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemInstance) \
	NO_API virtual ~UItemInstance();


#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_12_PROLOG
#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_15_INCLASS_NO_PURE_DECLS \
	FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UItemInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_Item_ItemInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
