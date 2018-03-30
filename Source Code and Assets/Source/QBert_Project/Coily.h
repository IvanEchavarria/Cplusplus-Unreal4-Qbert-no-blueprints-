// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Qbert_Project.h"
#include "GameFramework/Actor.h"
#include "Coily.generated.h"

UCLASS()
class QBERT_PROJECT_API ACoily : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoily();
	// Update Qbert position in the world
	void updateQbertPosition(int row, int col);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Coily world position row and colum
	int PositionIndexRow = 3;
	int PositionIndexCol = 7;
	//Qbert world position row and colum
	int QbertPositionIndexRow = 1;
	int QbertPositionIndexCol = 7;
	float clockToJump;
	float jumpDelay;
	bool  isSpawning;
	bool  isCoilyABall;
	bool  isLeaping;
	bool  landOnBlack;
	FVector leapDestination;
	FVector leapOfDeath;

	int lookAtDir;
	float speed;
	bool  isMoving;
	FVector spawnLocation;
	FVector newDestination;

	UPaperSprite *CoilyBallGround;
	UPaperSprite *CoilyBallJump;

	UPaperSprite *CoilyDownRightGround;
	UPaperSprite *CoilyDownRightJump;
	UPaperSprite *CoilyDownLeftGround;
	UPaperSprite *CoilyDownLeftJump;
	UPaperSprite *CoilyUpRightGround;
	UPaperSprite *CoilyUpRightJump;
	UPaperSprite *CoilyUpLeftGround;
	UPaperSprite *CoilyUpLeftJump;

	//Ball Jump sound
	USoundCue*       ballJumpSound;

	//Coily JumpSound
	UAudioComponent* jumpSoundComponent;
	USoundCue*       jumpSound;

	//Over the edge sound
	UAudioComponent* OverEdgeComponent;
	USoundCue*       OverEdgeSound;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coily", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* CoilySpriteComponent;

	// Input actions to coily around
	void DownRight();
	void DownLeft();
	void UpRight();
	void UpLeft();

	//Delay timer to take action
	void JumpToCubeTimer(float deltaTime);

	//Choose direction to jump to
	void chooseDirectionTowardsQbert();

	//Execute small leap to look like we are jumping to a cube and not sliding to it
	void leapToCube(float deltaTime);

	//Execute movement to final destination (land on cube)
	void MovingToCube(float deltaTime);

	//Execute death leap if we jump off the piramid of cubes
	void deathJump(float deltaTime);

	//Random value to decide direction
	int getRandomDirection();
	
};
