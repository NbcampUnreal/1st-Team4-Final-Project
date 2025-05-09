// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/BaseAIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EMBER_BaseAIController_generated_h
#error "BaseAIController.generated.h already included, missing '#pragma once' in BaseAIController.h"
#endif
#define EMBER_BaseAIController_generated_h

#define FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseAIController(); \
	friend struct Z_Construct_UClass_ABaseAIController_Statics; \
public: \
	DECLARE_CLASS(ABaseAIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(ABaseAIController)


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABaseAIController(ABaseAIController&&); \
	ABaseAIController(const ABaseAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseAIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseAIController) \
	NO_API virtual ~ABaseAIController();


#define FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_12_PROLOG
#define FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class ABaseAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_1st_Team4_Final_Project_Source_EMBER_AI_BaseAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
