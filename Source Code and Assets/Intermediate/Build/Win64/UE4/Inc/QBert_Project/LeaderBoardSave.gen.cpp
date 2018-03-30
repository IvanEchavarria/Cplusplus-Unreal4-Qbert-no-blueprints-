// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "LeaderBoardSave.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLeaderBoardSave() {}
// Cross Module References
	QBERT_PROJECT_API UClass* Z_Construct_UClass_ULeaderBoardSave_NoRegister();
	QBERT_PROJECT_API UClass* Z_Construct_UClass_ULeaderBoardSave();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	UPackage* Z_Construct_UPackage__Script_QBert_Project();
// End Cross Module References
	void ULeaderBoardSave::StaticRegisterNativesULeaderBoardSave()
	{
	}
	UClass* Z_Construct_UClass_ULeaderBoardSave_NoRegister()
	{
		return ULeaderBoardSave::StaticClass();
	}
	UClass* Z_Construct_UClass_ULeaderBoardSave()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_USaveGame();
			Z_Construct_UPackage__Script_QBert_Project();
			OuterClass = ULeaderBoardSave::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100080u;


				CPP_BOOL_PROPERTY_BITMASK_STRUCT(isListEmpty, ULeaderBoardSave);
				UProperty* NewProp_isListEmpty = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("isListEmpty"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(isListEmpty, ULeaderBoardSave), 0x0010000000020001, CPP_BOOL_PROPERTY_BITMASK(isListEmpty, ULeaderBoardSave), sizeof(bool), true);
				UProperty* NewProp_Scores = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Scores"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(Scores, ULeaderBoardSave), 0x0040000000020001);
				NewProp_Scores->ArrayDim = CPP_ARRAY_DIM(Scores, ULeaderBoardSave);
				UProperty* NewProp_Names = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Names"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Names, ULeaderBoardSave), 0x0040000000020001);
				NewProp_Names->ArrayDim = CPP_ARRAY_DIM(Names, ULeaderBoardSave);
				static TCppClassTypeInfo<TCppClassTypeTraits<ULeaderBoardSave> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("LeaderBoardSave.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("LeaderBoardSave.h"));
				MetaData->SetValue(NewProp_isListEmpty, TEXT("Category"), TEXT("Basic"));
				MetaData->SetValue(NewProp_isListEmpty, TEXT("ModuleRelativePath"), TEXT("LeaderBoardSave.h"));
				MetaData->SetValue(NewProp_Scores, TEXT("Category"), TEXT("Basic"));
				MetaData->SetValue(NewProp_Scores, TEXT("ModuleRelativePath"), TEXT("LeaderBoardSave.h"));
				MetaData->SetValue(NewProp_Names, TEXT("Category"), TEXT("Basic"));
				MetaData->SetValue(NewProp_Names, TEXT("ModuleRelativePath"), TEXT("LeaderBoardSave.h"));
				MetaData->SetValue(NewProp_Names, TEXT("ToolTip"), TEXT("Use this so it saves to the file?"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULeaderBoardSave, 4147014051);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULeaderBoardSave(Z_Construct_UClass_ULeaderBoardSave, &ULeaderBoardSave::StaticClass, TEXT("/Script/QBert_Project"), TEXT("ULeaderBoardSave"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULeaderBoardSave);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
