// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEMBER_init() {}
	EMBER_API UFunction* Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature();
	EMBER_API UFunction* Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_EMBER;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_EMBER()
	{
		if (!Z_Registration_Info_UPackage__Script_EMBER.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_EMBER_OnMoveDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_EMBER_StateTypeChanged__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/EMBER",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x993E55A4,
				0xDE49AB7B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_EMBER.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_EMBER.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_EMBER(Z_Construct_UPackage__Script_EMBER, TEXT("/Script/EMBER"), Z_Registration_Info_UPackage__Script_EMBER, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x993E55A4, 0xDE49AB7B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
