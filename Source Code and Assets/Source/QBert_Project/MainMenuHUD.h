// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "LeaderBoardSave.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class QBERT_PROJECT_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMainMenuHUD();

	virtual void DrawHUD() override;
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	//Ufont variable to hold the game's font and Material for the font
	UFont* QbertFont;
	UMaterial* FontMaterial;

	//Background color
	FColor BackgroundColor = FColor::FColor(34, 34, 109, 255);

	//Text color 
	FColor TextColor = FColor::FColor(142, 252, 63, 255);

	//Golden color
	FColor GoldColor = FColor::FColor(255, 201, 14, 255);

	//Qbert Title Texture
	UTexture* QbertTitle;

	//Viewport boolean 
	bool gotViewportsize;

	//show LeaderBoard Boolean
	bool lookAtLeaderBoard;
	bool hasLeaderBoardBeenUpdated;

	//Size of the viewport
	FVector2D viewPortSizeVector;
	int width;
	int height;
	int topOfScreenOffset = 150;
	float screenWidth = 650.0f;
	float screenHeight = 700.0f;
	float totalWidth;

public:

	void ShowLeaderBoard();

private:
	//Score holders
	FString  Names[10];
	int      Scores[10];
	FString  name = "Ivan";

	//Save Game Instance Pointer
	ULeaderBoardSave* saveGameInstance;

	
};
