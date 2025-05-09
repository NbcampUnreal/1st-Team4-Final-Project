// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/Task/BTT_Run.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EMBER_BTT_Run_generated_h
#error "BTT_Run.generated.h already included, missing '#pragma once' in BTT_Run.h"
#endif
#define EMBER_BTT_Run_generated_h

#define FID_PJ_Ember_Source_EMBER_AI_Task_BTT_Run_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBTT_Run(); \
	friend struct Z_Construct_UClass_UBTT_Run_Statics; \
public: \
	DECLARE_CLASS(UBTT_Run, UBTTask_BlackboardBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UBTT_Run)


#define FID_PJ_Ember_Source_EMBER_AI_Task_BTT_Run_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UBTT_Run(UBTT_Run&&); \
	UBTT_Run(const UBTT_Run&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBTT_Run); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBTT_Run); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBTT_Run) \
	NO_API virtual ~UBTT_Run();


#define FID_PJ_Ember_Source_EMBER_AI_Task_BTT_Run_h_12_PROLOG
#define FID_PJ_Ember_Source_EMBER_AI_Task_BTT_Run_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PJ_Ember_Source_EMBER_AI_Task_BTT_Run_h_15_INCLASS_NO_PURE_DECLS \
	FID_PJ_Ember_Source_EMBER_AI_Task_BTT_Run_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UBTT_Run>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PJ_Ember_Source_EMBER_AI_Task_BTT_Run_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
