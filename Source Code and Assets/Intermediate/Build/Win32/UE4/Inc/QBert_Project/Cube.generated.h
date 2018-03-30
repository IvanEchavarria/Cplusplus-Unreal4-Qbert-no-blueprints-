// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QBERT_PROJECT_Cube_generated_h
#error "Cube.generated.h already included, missing '#pragma once' in Cube.h"
#endif
#define QBERT_PROJECT_Cube_generated_h

#define QBert_Project_Source_QBert_Project_Cube_h_14_RPC_WRAPPERS
#define QBert_Project_Source_QBert_Project_Cube_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define QBert_Project_Source_QBert_Project_Cube_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACube(); \
	friend QBERT_PROJECT_API class UClass* Z_Construct_UClass_ACube(); \
public: \
	DECLARE_CLASS(ACube, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/QBert_Project"), NO_API) \
	DECLARE_SERIALIZER(ACube) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define QBert_Project_Source_QBert_Project_Cube_h_14_INCLASS \
private: \
	static void StaticRegisterNativesACube(); \
	friend QBERT_PROJECT_API class UClass* Z_Construct_UClass_ACube(); \
public: \
	DECLARE_CLASS(ACube, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/QBert_Project"), NO_API) \
	DECLARE_SERIALIZER(ACube) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define QBert_Project_Source_QBert_Project_Cube_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACube(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACube) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACube); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACube); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACube(ACube&&); \
	NO_API ACube(const ACube&); \
public:


#define QBert_Project_Source_QBert_Project_Cube_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACube(ACube&&); \
	NO_API ACube(const ACube&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACube); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACube); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACube)


#define QBert_Project_Source_QBert_Project_Cube_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CubeSprite() { return STRUCT_OFFSET(ACube, CubeSprite); }


#define QBert_Project_Source_QBert_Project_Cube_h_11_PROLOG
#define QBert_Project_Source_QBert_Project_Cube_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	QBert_Project_Source_QBert_Project_Cube_h_14_PRIVATE_PROPERTY_OFFSET \
	QBert_Project_Source_QBert_Project_Cube_h_14_RPC_WRAPPERS \
	QBert_Project_Source_QBert_Project_Cube_h_14_INCLASS \
	QBert_Project_Source_QBert_Project_Cube_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define QBert_Project_Source_QBert_Project_Cube_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	QBert_Project_Source_QBert_Project_Cube_h_14_PRIVATE_PROPERTY_OFFSET \
	QBert_Project_Source_QBert_Project_Cube_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	QBert_Project_Source_QBert_Project_Cube_h_14_INCLASS_NO_PURE_DECLS \
	QBert_Project_Source_QBert_Project_Cube_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID QBert_Project_Source_QBert_Project_Cube_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
