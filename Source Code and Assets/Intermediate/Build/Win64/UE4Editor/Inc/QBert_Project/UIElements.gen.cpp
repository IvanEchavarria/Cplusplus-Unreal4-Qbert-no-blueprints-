// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "UIElements.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUIElements() {}
// Cross Module References
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AUIElements_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AUIElements();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_QBert_Project();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbookComponent_NoRegister();
// End Cross Module References
	void AUIElements::StaticRegisterNativesAUIElements()
	{
	}
	UClass* Z_Construct_UClass_AUIElements_NoRegister()
	{
		return AUIElements::StaticClass();
	}
	UClass* Z_Construct_UClass_AUIElements()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_QBert_Project();
			OuterClass = AUIElements::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_PlayerTextUIAnimation = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PlayerTextUIAnimation"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(PlayerTextUIAnimation, AUIElements), 0x0040000000020015, Z_Construct_UClass_UPaperFlipbook_NoRegister());
				UProperty* NewProp_PlayerTextUIComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PlayerTextUIComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(PlayerTextUIComponent, AUIElements), 0x00400000000a001d, Z_Construct_UClass_UPaperFlipbookComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<AUIElements> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UIElements.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("UIElements.h"));
				MetaData->SetValue(NewProp_PlayerTextUIAnimation, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_PlayerTextUIAnimation, TEXT("Category"), TEXT("Flipbook"));
				MetaData->SetValue(NewProp_PlayerTextUIAnimation, TEXT("ModuleRelativePath"), TEXT("UIElements.h"));
				MetaData->SetValue(NewProp_PlayerTextUIComponent, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_PlayerTextUIComponent, TEXT("Category"), TEXT("Flipbook"));
				MetaData->SetValue(NewProp_PlayerTextUIComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_PlayerTextUIComponent, TEXT("ModuleRelativePath"), TEXT("UIElements.h"));
				MetaData->SetValue(NewProp_PlayerTextUIComponent, TEXT("ToolTip"), TEXT("Sprite Animation for PlayerText"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AUIElements, 804115321);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUIElements(Z_Construct_UClass_AUIElements, &AUIElements::StaticClass, TEXT("/Script/QBert_Project"), TEXT("AUIElements"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUIElements);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
