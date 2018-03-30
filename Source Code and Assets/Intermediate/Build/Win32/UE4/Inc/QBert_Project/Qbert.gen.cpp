// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Qbert.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQbert() {}
// Cross Module References
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AQbert_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AQbert();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_QBert_Project();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
// End Cross Module References
	void AQbert::StaticRegisterNativesAQbert()
	{
	}
	UClass* Z_Construct_UClass_AQbert_NoRegister()
	{
		return AQbert::StaticClass();
	}
	UClass* Z_Construct_UClass_AQbert()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage__Script_QBert_Project();
			OuterClass = AQbert::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_QbertSprite = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("QbertSprite"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(QbertSprite, AQbert), 0x00400000000a001d, Z_Construct_UClass_UPaperSpriteComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<AQbert> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Qbert.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Qbert.h"));
				MetaData->SetValue(NewProp_QbertSprite, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_QbertSprite, TEXT("Category"), TEXT("Qbert"));
				MetaData->SetValue(NewProp_QbertSprite, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_QbertSprite, TEXT("ModuleRelativePath"), TEXT("Qbert.h"));
				MetaData->SetValue(NewProp_QbertSprite, TEXT("ToolTip"), TEXT("Adding a comment here creates a tooltip for the Uproperty in the engine( Debug Tool) - UPROPERTY for ArrowComponent\nEditAnywhere to allow edit in the editor, VisibleAnywhere to see only in the editor, BlueprintReadOnly = Allow the blueprint to read the state only, BlueprintReadWrite = allow blueprint to modify\nCategory = category it will appear under in the editor\nSprite for Qbert"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AQbert, 3256846953);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AQbert(Z_Construct_UClass_AQbert, &AQbert::StaticClass, TEXT("/Script/QBert_Project"), TEXT("AQbert"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AQbert);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
