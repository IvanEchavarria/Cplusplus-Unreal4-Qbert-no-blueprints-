// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Elevator.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeElevator() {}
// Cross Module References
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AElevator_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AElevator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_QBert_Project();
// End Cross Module References
	void AElevator::StaticRegisterNativesAElevator()
	{
	}
	UClass* Z_Construct_UClass_AElevator_NoRegister()
	{
		return AElevator::StaticClass();
	}
	UClass* Z_Construct_UClass_AElevator()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_QBert_Project();
			OuterClass = AElevator::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<AElevator> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Elevator.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Elevator.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AElevator, 576938570);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AElevator(Z_Construct_UClass_AElevator, &AElevator::StaticClass, TEXT("/Script/QBert_Project"), TEXT("AElevator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AElevator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
