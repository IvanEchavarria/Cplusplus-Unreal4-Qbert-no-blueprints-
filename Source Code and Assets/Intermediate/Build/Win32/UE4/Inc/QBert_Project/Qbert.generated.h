// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef QBERT_PROJECT_Qbert_generated_h
#error "Qbert.generated.h already included, missing '#pragma once' in Qbert.h"
#endif
#define QBERT_PROJECT_Qbert_generated_h

#define QBert_Project_Source_QBert_Project_Qbert_h_13_RPC_WRAPPERS
#define QBert_Project_Source_QBert_Project_Qbert_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define QBert_Project_Source_QBert_Project_Qbert_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAQbert(); \
	friend QBERT_PROJECT_API class UClass* Z_Construct_UClass_AQbert(); \
public: \
	DECLARE_CLASS(AQbert, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/QBert_Project"), NO_API) \
	DECLARE_SERIALIZER(AQbert) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define QBert_Project_Source_QBert_Project_Qbert_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAQbert(); \
	friend QBERT_PROJECT_API class UClass* Z_Construct_UClass_AQbert(); \
public: \
	DECLARE_CLASS(AQbert, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/QBert_Project"), NO_API) \
	DECLARE_SERIALIZER(AQbert) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define QBert_Project_Source_QBert_Project_Qbert_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AQbert(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AQbert) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQbert); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQbert); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQbert(AQbert&&); \
	NO_API AQbert(const AQbert&); \
public:


#define QBert_Project_Source_QBert_Project_Qbert_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AQbert(AQbert&&); \
	NO_API AQbert(const AQbert&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AQbert); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AQbert); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AQbert)


#define QBert_Project_Source_QBert_Project_Qbert_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__QbertSprite() { return STRUCT_OFFSET(AQbert, QbertSprite); }


#define QBert_Project_Source_QBert_Project_Qbert_h_10_PROLOG
#define QBert_Project_Source_QBert_Project_Qbert_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	QBert_Project_Source_QBert_Project_Qbert_h_13_PRIVATE_PROPERTY_OFFSET \
	QBert_Project_Source_QBert_Project_Qbert_h_13_RPC_WRAPPERS \
	QBert_Project_Source_QBert_Project_Qbert_h_13_INCLASS \
	QBert_Project_Source_QBert_Project_Qbert_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define QBert_Project_Source_QBert_Project_Qbert_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	QBert_Project_Source_QBert_Project_Qbert_h_13_PRIVATE_PROPERTY_OFFSET \
	QBert_Project_Source_QBert_Project_Qbert_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	QBert_Project_Source_QBert_Project_Qbert_h_13_INCLASS_NO_PURE_DECLS \
	QBert_Project_Source_QBert_Project_Qbert_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID QBert_Project_Source_QBert_Project_Qbert_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
