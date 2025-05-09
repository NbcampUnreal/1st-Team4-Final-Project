// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/BaseAI.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef EMBER_BaseAI_generated_h
#error "BaseAI.generated.h already included, missing '#pragma once' in BaseAI.h"
#endif
#define EMBER_BaseAI_generated_h

#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPerceptionUpdated); \
	DECLARE_FUNCTION(execOnDeath); \
	DECLARE_FUNCTION(execAttack);


#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseAI(); \
	friend struct Z_Construct_UClass_ABaseAI_Statics; \
public: \
	DECLARE_CLASS(ABaseAI, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(ABaseAI)


#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABaseAI(ABaseAI&&); \
	ABaseAI(const ABaseAI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseAI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseAI); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseAI) \
	NO_API virtual ~ABaseAI();


#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_21_PROLOG
#define FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_24_INCLASS_NO_PURE_DECLS \
	FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class ABaseAI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_code_NBCamp_1st_Team4_Final_Project_Source_EMBER_AI_BaseAI_h


#define FOREACH_ENUM_AISOUNDCATEGORY(op) \
	op(AISoundCategory::MoveSound) \
	op(AISoundCategory::AttackSound) \
	op(AISoundCategory::HitSound) \
	op(AISoundCategory::DeathSound) 

enum class AISoundCategory : uint8;
template<> struct TIsUEnumClass<AISoundCategory> { enum { Value = true }; };
template<> EMBER_API UEnum* StaticEnum<AISoundCategory>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
