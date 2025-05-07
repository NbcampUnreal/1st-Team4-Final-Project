// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEMBER_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_EMBER;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_EMBER()
	{
		if (!Z_Registration_Info_UPackage__Script_EMBER.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/EMBER",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x2A723CBE,
				0x4C97ED78,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_EMBER.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_EMBER.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_EMBER(Z_Construct_UPackage__Script_EMBER, TEXT("/Script/EMBER"), Z_Registration_Info_UPackage__Script_EMBER, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x2A723CBE, 0x4C97ED78));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
