// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Component/MontageSystemComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
#ifdef EMBER_MontageSystemComponent_generated_h
#error "MontageSystemComponent.generated.h already included, missing '#pragma once' in MontageSystemComponent.h"
#endif
#define EMBER_MontageSystemComponent_generated_h

#define FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void MulticastPlayMontage_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName); \
	virtual bool ServerPlayMontage_Validate(UAnimMontage* , float , FName ); \
	virtual void ServerPlayMontage_Implementation(UAnimMontage* Montage, float PlayRate, FName SectionName); \
	DECLARE_FUNCTION(execMulticastPlayMontage); \
	DECLARE_FUNCTION(execServerPlayMontage); \
	DECLARE_FUNCTION(execRequestPlayMontage);


#define FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_CALLBACK_WRAPPERS
#define FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMontageSystemComponent(); \
	friend struct Z_Construct_UClass_UMontageSystemComponent_Statics; \
public: \
	DECLARE_CLASS(UMontageSystemComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EMBER"), NO_API) \
	DECLARE_SERIALIZER(UMontageSystemComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentMontage=NETFIELD_REP_START, \
		NETFIELD_REP_END=CurrentMontage	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMontageSystemComponent(UMontageSystemComponent&&); \
	UMontageSystemComponent(const UMontageSystemComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMontageSystemComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMontageSystemComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMontageSystemComponent) \
	NO_API virtual ~UMontageSystemComponent();


#define FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_11_PROLOG
#define FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_CALLBACK_WRAPPERS \
	FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_INCLASS_NO_PURE_DECLS \
	FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EMBER_API UClass* StaticClass<class UMontageSystemComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_1st_Team4_Final_Project_Source_EMBER_Component_MontageSystemComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
