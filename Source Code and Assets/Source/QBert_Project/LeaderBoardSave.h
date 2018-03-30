// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LeaderBoardSave.generated.h"

/**
 * 
 */
UCLASS()
class QBERT_PROJECT_API ULeaderBoardSave : public USaveGame
{
	GENERATED_BODY()
	
public:
	//ULeaderBoardSave();
	
private:
	UPROPERTY(VisibleAnywhere, Category = Basic) // Use this so it saves to the file? 
	FString  Names[10];

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int      Scores[10];

	int      listLenght = 10;

public:
	UPROPERTY(VisibleAnywhere, Category = Basic)
	bool isListEmpty = true;

	void InitializeLeaderBoard();

	void addScorer(FString n, int s);

	FString* getNamesPointer();

	int* getScoresPointer();
	
};
