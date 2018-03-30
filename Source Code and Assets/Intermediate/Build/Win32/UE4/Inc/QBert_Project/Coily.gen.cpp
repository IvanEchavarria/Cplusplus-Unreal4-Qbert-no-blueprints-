// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Coily.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCoily() {}
// Cross Module References
	QBERT_PROJECT_API UClass* Z_Construct_UClass_ACoily_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_ACoily();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_QBert_Project();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
// End Cross Module References
	void ACoily::StaticRegisterNativesACoily()
	{
	}
	UClass* Z_Construct_UClass_ACoily_NoRegister()
	{
		return ACoily::StaticClass();
	}
	UClass* Z_Construct_UClass_ACoily()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_QBert_Project();
			OuterClass = ACoily::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_CoilySpriteComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CoilySpriteComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CoilySpriteComponent, ACoily), 0x00400000000a001d, Z_Construct_UClass_UPaperSpriteComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<ACoily> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Coily.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Coily.h"));
				MetaData->SetValue(NewProp_CoilySpriteComponent, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_CoilySpriteComponent, TEXT("Category"), TEXT("Coily"));
				MetaData->SetValue(NewProp_CoilySpriteComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CoilySpriteComponent, TEXT("ModuleRelativePath"), TEXT("Coily.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACoily, 299441851);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACoily(Z_Construct_UClass_ACoily, &ACoily::StaticClass, TEXT("/Script/QBert_Project"), TEXT("ACoily"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACoily);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
