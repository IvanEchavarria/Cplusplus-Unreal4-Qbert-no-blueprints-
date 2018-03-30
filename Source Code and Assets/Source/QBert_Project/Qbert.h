// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Qbert_Project.h" // This class contains all the below headers that are commented out since they are being repeated on many other classes
#include "QBERTGameMode.h"
#include "GameFramework/Pawn.h"
#include "Qbert.generated.h"

class UPaperSprite;
UCLASS()
class QBERT_PROJECT_API AQbert : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AQbert();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	int PositionIndexRow = 1;
	int PositionIndexCol = 7;
	int blockValue = 9;
	int lookAtDir;
	float speed;
	float unPauseClock;
	bool  isOnElevator;
	bool isLeaping;
	bool  isMoving;
	bool  landOnBlack;
	bool  pauseGame;
	FVector leapDestination;
	FVector newDestination;
	FVector leapOfDeath;
	FVector topOfPlatform;

	AQBERTGameMode *WorldGameMode;

	UPaperSprite *QbertDownRightGround;
	UPaperSprite *QbertDownRightJump;
	UPaperSprite *QbertDownLeftGround;
	UPaperSprite *QbertDownLeftJump;
	UPaperSprite *QbertUpRightGround;
	UPaperSprite *QbertUpRightJump;
	UPaperSprite *QbertUpLeftGround;
	UPaperSprite *QbertUpLeftJump;

	//Sound objects
	UAudioComponent* jumpSoundComponent;
	USoundCue*       jumpSound;

	//Over the edge sound
	UAudioComponent* OverEdgeComponent;
	USoundCue*       OverEdgeSound;


	//Adding a comment here creates a tooltip for the Uproperty in the engine( Debug Tool) - UPROPERTY for ArrowComponent
	//EditAnywhere to allow edit in the editor, VisibleAnywhere to see only in the editor, BlueprintReadOnly = Allow the blueprint to read the state only, BlueprintReadWrite = allow blueprint to modify
	//Category = category it will appear under in the editor
	//Sprite for Qbert
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Qbert", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* QbertSprite;

	//Player controller
	APlayerController* playerController;

	// Input actions to move the player
	void DownRight();
	void DownLeft();
	void UpRight();
	void UpLeft();

	//Input to pause the game
	void Pausegame();

	//Input to exit game
	void ExitGame();

	//Execute small leap to look like we are jumping to a cube and not sliding to it
	void leapToCube(float deltaTime);

	//Execute movement to final destination (land on cube)
	void MovingToCube(float deltaTime);

	//Execute death leap if we jump off the piramid of cubes
	void deathJump(float deltaTime);
};
