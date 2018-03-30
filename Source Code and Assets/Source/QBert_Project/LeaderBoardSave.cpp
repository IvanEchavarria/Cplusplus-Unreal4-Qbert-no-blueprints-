// Fill out your copyright notice in the Description page of Project Settings.

#include "LeaderBoardSave.h"

void ULeaderBoardSave::InitializeLeaderBoard()
{	
	UE_LOG(LogTemp, Warning, TEXT("List is empty"));

	for (int i = 0; i < listLenght; i++)
	{
		Names[i] = "IE";
		Scores[i] = 0;
	}
	isListEmpty = false;
}

void ULeaderBoardSave::addScorer(FString n, int s)
{
	for (int i = 0; i < listLenght; i++)
	{
		if (s > Scores[i])
		{
			Names[i] = n;
			Scores[i] = s;
			isListEmpty = false;
			return;
		}
	}
}

FString* ULeaderBoardSave::getNamesPointer()
{
	return Names;
}

int* ULeaderBoardSave::getScoresPointer()
{
	return Scores;
}

