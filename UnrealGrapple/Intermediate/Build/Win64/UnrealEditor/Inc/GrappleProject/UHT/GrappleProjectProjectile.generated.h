// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GrappleProjectProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef GRAPPLEPROJECT_GrappleProjectProjectile_generated_h
#error "GrappleProjectProjectile.generated.h already included, missing '#pragma once' in GrappleProjectProjectile.h"
#endif
#define GRAPPLEPROJECT_GrappleProjectProjectile_generated_h

#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_SPARSE_DATA
#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_ACCESSORS
#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGrappleProjectProjectile(); \
	friend struct Z_Construct_UClass_AGrappleProjectProjectile_Statics; \
public: \
	DECLARE_CLASS(AGrappleProjectProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GrappleProject"), NO_API) \
	DECLARE_SERIALIZER(AGrappleProjectProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGrappleProjectProjectile(); \
	friend struct Z_Construct_UClass_AGrappleProjectProjectile_Statics; \
public: \
	DECLARE_CLASS(AGrappleProjectProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GrappleProject"), NO_API) \
	DECLARE_SERIALIZER(AGrappleProjectProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGrappleProjectProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGrappleProjectProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGrappleProjectProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGrappleProjectProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGrappleProjectProjectile(AGrappleProjectProjectile&&); \
	NO_API AGrappleProjectProjectile(const AGrappleProjectProjectile&); \
public: \
	NO_API virtual ~AGrappleProjectProjectile();


#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGrappleProjectProjectile(AGrappleProjectProjectile&&); \
	NO_API AGrappleProjectProjectile(const AGrappleProjectProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGrappleProjectProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGrappleProjectProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGrappleProjectProjectile) \
	NO_API virtual ~AGrappleProjectProjectile();


#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_12_PROLOG
#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_SPARSE_DATA \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_RPC_WRAPPERS \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_ACCESSORS \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_INCLASS \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_SPARSE_DATA \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_ACCESSORS \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GRAPPLEPROJECT_API UClass* StaticClass<class AGrappleProjectProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_3_GrappleProjectAfterTesting_Source_GrappleProject_GrappleProjectProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
