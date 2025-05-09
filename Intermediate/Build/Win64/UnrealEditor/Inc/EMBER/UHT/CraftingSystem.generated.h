// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Crafting/CraftingSystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class AEmberPlayerCharacter;
#ifdef EMBER_CraftingSystem_generated_h
#error "CraftingSystem.generated.h already included, missing '#pragma once' in CraftingSystem.h"
#endif
#define EMBER_CraftingSystem_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAggregateIngredients); \
	DECLARE_FUNCTION(execStartCrafting);


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCraftingSystem(); \
	friend struct Z_Construct_UClass_UCraftingSystem_Statics; \
public: \
	DECLARE_CLASS(UCraftingSystem, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UCraftingSystem)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCraftingSystem(UCraftingSystem&&); \
	UCraftingSystem(const UCraftingSystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCraftingSystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCraftingSystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCraftingSystem) \
	NO_API virtual ~UCraftingSystem();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_8_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_11_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UCraftingSystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_Crafting_CraftingSystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
