// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Cube.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCube() {}
// Cross Module References
	QBERT_PROJECT_API UClass* Z_Construct_UClass_ACube_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_ACube();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_QBert_Project();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
// End Cross Module References
	void ACube::StaticRegisterNativesACube()
	{
	}
	UClass* Z_Construct_UClass_ACube_NoRegister()
	{
		return ACube::StaticClass();
	}
	UClass* Z_Construct_UClass_ACube()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_QBert_Project();
			OuterClass = ACube::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_CubeSprite = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CubeSprite"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CubeSprite, ACube), 0x00400000000a001d, Z_Construct_UClass_UPaperSpriteComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<ACube> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Cube.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Cube.h"));
				MetaData->SetValue(NewProp_CubeSprite, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_CubeSprite, TEXT("Category"), TEXT("CubeType"));
				MetaData->SetValue(NewProp_CubeSprite, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CubeSprite, TEXT("ModuleRelativePath"), TEXT("Cube.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACube, 1300010153);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACube(Z_Construct_UClass_ACube, &ACube::StaticClass, TEXT("/Script/QBert_Project"), TEXT("ACube"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACube);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
