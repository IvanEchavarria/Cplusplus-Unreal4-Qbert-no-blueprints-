// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "QBERTGameMode.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQBERTGameMode() {}
// Cross Module References
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AQBERTGameMode_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AQBERTGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_QBert_Project();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_ACube_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AUIElements_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_AElevator_NoRegister();
// End Cross Module References
	void AQBERTGameMode::StaticRegisterNativesAQBERTGameMode()
	{
	}
	UClass* Z_Construct_UClass_AQBERTGameMode_NoRegister()
	{
		return AQBERTGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_AQBERTGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_QBert_Project();
			OuterClass = AQBERTGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900288u;


				UProperty* NewProp_tempCube = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("tempCube"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(tempCube, AQBERTGameMode), 0x0044000000020015, Z_Construct_UClass_ACube_NoRegister(), Z_Construct_UClass_UClass());
				UProperty* NewProp_tempUI = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("tempUI"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(tempUI, AQBERTGameMode), 0x0044000000020015, Z_Construct_UClass_AUIElements_NoRegister(), Z_Construct_UClass_UClass());
				UProperty* NewProp_ElevatorObj2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ElevatorObj2"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ElevatorObj2, AQBERTGameMode), 0x0040000000020015, Z_Construct_UClass_AElevator_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<AQBERTGameMode> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("QBERTGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("QBERTGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("Let this know what a ACube class is"));
				MetaData->SetValue(NewProp_tempCube, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_tempCube, TEXT("Category"), TEXT("Cube"));
				MetaData->SetValue(NewProp_tempCube, TEXT("ModuleRelativePath"), TEXT("QBERTGameMode.h"));
				MetaData->SetValue(NewProp_tempUI, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_tempUI, TEXT("Category"), TEXT("UI"));
				MetaData->SetValue(NewProp_tempUI, TEXT("ModuleRelativePath"), TEXT("QBERTGameMode.h"));
				MetaData->SetValue(NewProp_tempUI, TEXT("ToolTip"), TEXT("This Subclasses are not necessary to spawn the actors"));
				MetaData->SetValue(NewProp_ElevatorObj2, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_ElevatorObj2, TEXT("Category"), TEXT("Elevators"));
				MetaData->SetValue(NewProp_ElevatorObj2, TEXT("ModuleRelativePath"), TEXT("QBERTGameMode.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AQBERTGameMode, 620918909);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AQBERTGameMode(Z_Construct_UClass_AQBERTGameMode, &AQBERTGameMode::StaticClass, TEXT("/Script/QBert_Project"), TEXT("AQBERTGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AQBERTGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
