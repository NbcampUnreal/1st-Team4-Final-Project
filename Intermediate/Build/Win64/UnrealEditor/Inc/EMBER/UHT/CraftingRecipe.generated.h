// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Crafting/CraftingRecipe.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
#ifdef EMBER_CraftingRecipe_generated_h
#error "CraftingRecipe.generated.h already included, missing '#pragma once' in CraftingRecipe.h"
#endif
#define EMBER_CraftingRecipe_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCanCombine);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCraftingRecipe(); \
	friend struct Z_Construct_UClass_UCraftingRecipe_Statics; \
public: \
	DECLARE_CLASS(UCraftingRecipe, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UCraftingRecipe)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCraftingRecipe(UCraftingRecipe&&); \
	UCraftingRecipe(const UCraftingRecipe&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCraftingRecipe); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCraftingRecipe); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCraftingRecipe) \
	NO_API virtual ~UCraftingRecipe();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_7_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_10_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UCraftingRecipe>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipe_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
