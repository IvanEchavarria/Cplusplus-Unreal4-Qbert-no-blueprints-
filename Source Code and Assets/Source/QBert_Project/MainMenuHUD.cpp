// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuHUD.h"

AMainMenuHUD::AMainMenuHUD()
{
	//Find Font and Material for the font

	static ConstructorHelpers::FObjectFinder<UFont> QbertFontAsset(TEXT("/Game/QBertFolders/Font/QbertRevised_Font.QbertRevised_Font"));
	static ConstructorHelpers::FObjectFinder<UMaterial> QbertFontMaterial(TEXT("/Game/QBertFolders/Font/MyTextMaterial.MyTextMaterial"));

	QbertFont = QbertFontAsset.Object;
	FontMaterial = QbertFontMaterial.Object;

	//Setup QbertTitle Texture
	static ConstructorHelpers::FObjectFinder<UTexture> QbertTitleTextureAsset(TEXT("/Game/QBertFolders/Sprites/UI/QbertTitle.QbertTitle"));

	QbertTitle = QbertTitleTextureAsset.Object;

	lookAtLeaderBoard = false;
	hasLeaderBoardBeenUpdated = false;
	gotViewportsize = false;
	
}

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();	

	//Check if saved game has been created

	if (UGameplayStatics::DoesSaveGameExist("Slot0", 0))
	{
		saveGameInstance = Cast<ULeaderBoardSave>(UGameplayStatics::LoadGameFromSlot(TEXT("Slot0"), 0));
		//Load info from the current save instance to populate the list
		FString* tempNames = saveGameInstance->getNamesPointer();
		int*     tempScores = saveGameInstance->getScoresPointer();

		for (int i = 0; i < 10; i++)
		{
			Names[i] = tempNames[i];
			Scores[i] = tempScores[i];
		}
		hasLeaderBoardBeenUpdated = true;
	}
	else
	{
		//If there is no save instance then create one for the first time.
		saveGameInstance = Cast<ULeaderBoardSave>(UGameplayStatics::CreateSaveGameObject(ULeaderBoardSave::StaticClass()));
		saveGameInstance->InitializeLeaderBoard();
		UGameplayStatics::SaveGameToSlot(saveGameInstance, TEXT("Slot0"), 0);
	}
}


//Main draw loop for the hud
void AMainMenuHUD::DrawHUD()
{
	Super::DrawHUD();

	if (GetWorld() && !gotViewportsize)
	{
		GEngine->GameViewport->GetViewportSize(viewPortSizeVector);
		width = viewPortSizeVector.X;
		height = viewPortSizeVector.Y;

		if (width != 0)
		{
			gotViewportsize = true;
		}
		
	}

	totalWidth = width / 2 - screenWidth/2;

	DrawRect(FLinearColor::FLinearColor(BackgroundColor), totalWidth, topOfScreenOffset, screenWidth, screenHeight);
	DrawTextureSimple(QbertTitle, totalWidth + 45.0f, topOfScreenOffset + 20.0f, 2.5f);
	DrawText(TEXT("Credits"), FLinearColor::FLinearColor(TextColor), totalWidth + 470.0f, topOfScreenOffset + 90.0f, QbertFont, 1.5f);
	DrawText(TEXT("Press: \n Enter to Start Game \n L for Leader Board \n Q to Exit Game "), FLinearColor::FLinearColor(GoldColor), totalWidth + 45.0f, topOfScreenOffset + 480.0f, QbertFont, 1.5f);
	
	
	//Draw on screen main text
	if (!lookAtLeaderBoard)
	{
		DrawText(TEXT("Jump on squares to \nchange them to \nthe target color"), FLinearColor::FLinearColor(TextColor), totalWidth + 155.0f, topOfScreenOffset + 120.0f, QbertFont, 1.5f);

		DrawText(TEXT("Stay on playfield! \njumping off results \nin a fatal plummet \nunless a disk is there"), FLinearColor::FLinearColor(TextColor), totalWidth + 175.0f, topOfScreenOffset + 200.0f, QbertFont, 1.5f);

		DrawText(TEXT("Avoid all objects \nand creatures that \nare not green"), FLinearColor::FLinearColor(TextColor), totalWidth + 195.0f, topOfScreenOffset + 300.0f, QbertFont, 1.5f);

		DrawText(TEXT("Use spinning disks \nto lure snake to \nhis death"), FLinearColor::FLinearColor(TextColor), totalWidth + 215.0f, topOfScreenOffset + 380.0f, QbertFont, 1.5f);
		
	}

	//Draw leader Board information
	
	if (lookAtLeaderBoard)
	{	
		float textX = totalWidth + 45.0f; //295.0f;

		DrawText("Leader Board      Scores", FLinearColor::FLinearColor(GoldColor), textX, topOfScreenOffset + 120.0f, QbertFont, 1.5f);

		DrawText(Names[0] + "                  " + FString::FromInt(Scores[0]), FLinearColor::FLinearColor(GoldColor), textX, topOfScreenOffset + 150.0f, QbertFont, 1.5f);
		  
		DrawText(Names[1] + "                  " + FString::FromInt(Scores[1]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 180.0f, QbertFont, 1.5f);

		DrawText(Names[2] + "                  " + FString::FromInt(Scores[2]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 210.0f, QbertFont, 1.5f);

		DrawText(Names[3] + "                  " + FString::FromInt(Scores[3]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 240.0f, QbertFont, 1.5f);

		DrawText(Names[4] + "                  " + FString::FromInt(Scores[4]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 270.0f, QbertFont, 1.5f);

		DrawText(Names[5] + "                  " + FString::FromInt(Scores[5]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 300.0f, QbertFont, 1.5f);
		 
		DrawText(Names[6] + "                  " + FString::FromInt(Scores[6]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 330.0f, QbertFont, 1.5f);

		DrawText(Names[7] + "                  " + FString::FromInt(Scores[7]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 360.0f, QbertFont, 1.5f);

		DrawText(Names[8] + "                  " + FString::FromInt(Scores[8]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 390.0f, QbertFont, 1.5f);

		DrawText(Names[9] + "                  " + FString::FromInt(Scores[9]), FLinearColor::FLinearColor(TextColor), textX, topOfScreenOffset + 420.0f, QbertFont, 1.5f);
	}

		
}

void AMainMenuHUD::ShowLeaderBoard()
{
	if (!lookAtLeaderBoard)
	{
		if (!hasLeaderBoardBeenUpdated)
		{
			FString* tempNames = saveGameInstance->getNamesPointer();
			int*     tempScores = saveGameInstance->getScoresPointer();

			for (int i = 0; i < 10; i++)
			{
				Names[i] = tempNames[i];
				Scores[i] = tempScores[i];
			}

			hasLeaderBoardBeenUpdated = true;
		}

		lookAtLeaderBoard = true;
		
	}
	else
	{
		lookAtLeaderBoard = false;
		//saveGameInstance->addScorer("ID", 450);
		//Save modified save Instance
		//UGameplayStatics::SaveGameToSlot(saveGameInstance, TEXT("Slot0"), 0);
		//hasLeaderBoardBeenUpdated = false;
	}
	
}