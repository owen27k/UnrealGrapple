// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GrappleProject/GrappleProjectGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGrappleProjectGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	GRAPPLEPROJECT_API UClass* Z_Construct_UClass_AGrappleProjectGameMode();
	GRAPPLEPROJECT_API UClass* Z_Construct_UClass_AGrappleProjectGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GrappleProject();
// End Cross Module References
	void AGrappleProjectGameMode::StaticRegisterNativesAGrappleProjectGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGrappleProjectGameMode);
	UClass* Z_Construct_UClass_AGrappleProjectGameMode_NoRegister()
	{
		return AGrappleProjectGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGrappleProjectGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGrappleProjectGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GrappleProject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGrappleProjectGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GrappleProjectGameMode.h" },
		{ "ModuleRelativePath", "GrappleProjectGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGrappleProjectGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGrappleProjectGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGrappleProjectGameMode_Statics::ClassParams = {
		&AGrappleProjectGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGrappleProjectGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGrappleProjectGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGrappleProjectGameMode()
	{
		if (!Z_Registration_Info_UClass_AGrappleProjectGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGrappleProjectGameMode.OuterSingleton, Z_Construct_UClass_AGrappleProjectGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGrappleProjectGameMode.OuterSingleton;
	}
	template<> GRAPPLEPROJECT_API UClass* StaticClass<AGrappleProjectGameMode>()
	{
		return AGrappleProjectGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGrappleProjectGameMode);
	AGrappleProjectGameMode::~AGrappleProjectGameMode() {}
	struct Z_CompiledInDeferFile_FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGrappleProjectGameMode, AGrappleProjectGameMode::StaticClass, TEXT("AGrappleProjectGameMode"), &Z_Registration_Info_UClass_AGrappleProjectGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGrappleProjectGameMode), 2859205039U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectGameMode_h_4232090754(TEXT("/Script/GrappleProject"),
		Z_CompiledInDeferFile_FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
