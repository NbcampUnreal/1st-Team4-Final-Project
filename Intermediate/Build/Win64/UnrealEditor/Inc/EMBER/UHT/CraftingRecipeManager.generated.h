// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Crafting/CraftingRecipeManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCraftingRecipe;
#ifdef EMBER_CraftingRecipeManager_generated_h
#error "CraftingRecipeManager.generated.h already included, missing '#pragma once' in CraftingRecipeManager.h"
#endif
#define EMBER_CraftingRecipeManager_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRecipeByName);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCraftingRecipeManager(); \
	friend struct Z_Construct_UClass_UCraftingRecipeManager_Statics; \
public: \
	DECLARE_CLASS(UCraftingRecipeManager, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UCraftingRecipeManager)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCraftingRecipeManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCraftingRecipeManager(UCraftingRecipeManager&&); \
	UCraftingRecipeManager(const UCraftingRecipeManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCraftingRecipeManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCraftingRecipeManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCraftingRecipeManager) \
	NO_API virtual ~UCraftingRecipeManager();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_8_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_11_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UCraftingRecipeManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingRecipeManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
