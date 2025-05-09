// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item/ItemTemplate.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UItemFragment;
#ifdef EMBER_ItemTemplate_generated_h
#error "ItemTemplate.generated.h already included, missing '#pragma once' in ItemTemplate.h"
#endif
#define EMBER_ItemTemplate_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUItemFragment(); \
	friend struct Z_Construct_UClass_UItemFragment_Statics; \
public: \
	DECLARE_CLASS(UItemFragment, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UItemFragment)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UItemFragment(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UItemFragment(UItemFragment&&); \
	UItemFragment(const UItemFragment&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemFragment); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemFragment); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemFragment) \
	NO_API virtual ~UItemFragment();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_10_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_13_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UItemFragment>();

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindFragmentByClass);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUItemTemplate(); \
	friend struct Z_Construct_UClass_UItemTemplate_Statics; \
public: \
	DECLARE_CLASS(UItemTemplate, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UItemTemplate)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UItemTemplate(UItemTemplate&&); \
	UItemTemplate(const UItemTemplate&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemTemplate); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemTemplate); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemTemplate) \
	NO_API virtual ~UItemTemplate();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_19_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_22_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UItemTemplate>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_Item_ItemTemplate_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
