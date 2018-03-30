// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Qbert_Project.h" // This class contains all the below headers that are commented out since they are being repeated on many other classes
#include "GameFramework/Actor.h"
#include "UIElements.generated.h"

UCLASS()
class QBERT_PROJECT_API AUIElements : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIElements();
	void showPausedOptions(bool isPaused);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	//SceneComponent holder for level text and level Text Sprite
	USceneComponent* LevelTextHolder;  //**************************USceneComponents are being use as dummy holders for the text so we can move 
																// them around to a relative location from the rootComponent
	UPaperSpriteComponent* LevelUIText;

	//Scene Component holder for Round Text and round text sprite

	USceneComponent* RoundTextHolder;

	UPaperSpriteComponent* RoundUIText;

	//Scene Component holder for ChangeTo Text and ChangeTo text sprite

	USceneComponent* ChangeToTextHolder;

	UPaperSpriteComponent* ChangeToUIText;

	//Scene Component holder for ChangeTo Cube Sprite 

	USceneComponent* ChangeToCubeHolder;

	UPaperSpriteComponent* ChangeToCubeUI;

	//Scene Component holder for Player Number Sprite 

	USceneComponent* PlayerNumberHolder;

	UPaperSpriteComponent* PlayerNumberUI;

	// Sprite animation for Arrows UI
	USceneComponent*	     ArrowsUIHolder;
	UPaperFlipbookComponent* ArrowsUIComponent;
	UPaperFlipbook*			 ArrowsUIAnimation;


	//Sprite Animation for PlayerText
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flipbook", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* PlayerTextUIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flipbook", meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbook* PlayerTextUIAnimation;

	//Ufont variable to hold the game's font and Material for the font
	UFont* QbertFont;
	UMaterial* FontMaterial;

	//Setup TextRenderer to show the score
	USceneComponent*	  ScoreUIHolder;
	UTextRenderComponent *ScoreText;	
	FText ScoreString;
	int score;

	//Setup TextRenderer to show the Level number
	USceneComponent*	 LevelNumberHolder;
	UTextRenderComponent *LevelNumberText;
	FText LevelNumberString;
	int LevelNumber;

	//Setup TextRenderer to show the Round number
	USceneComponent*	 RoundNumberHolder;
	UTextRenderComponent *RoundNumberText;
	FText RoundNumberString;
	int RoundNumber;

	//Setup TextRenderer to show pause options
	USceneComponent*	  PauseOptionsHolder;
	UTextRenderComponent *PauseOptionsText;
	//FText PauseOptionsString;

	//Scene Component holder for Lives Sprite 
	USceneComponent*	   LivesUIHolder;		
	UPaperSprite		  *LivesSprite;
	USceneComponent*	   LivesSpriteArray[9];

	int NumberOfLives = 1;
	int indexSecondRowLives = 0;

	FRotator SpriteVisible = FRotator(0.0f, 0.0f, 0.0f);
	FRotator SpriteInvisible = FRotator(0.0f, 90.0f, 0.0f);
	
};
