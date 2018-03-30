// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Qbert_Project.h"
#include "math.h"
#include "GameFramework/Actor.h"
#include "RedBall.generated.h"

UCLASS()
class QBERT_PROJECT_API ARedBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	int PositionIndexRow = 2;
	int PositionIndexCol = 6;
	float clockToJump;
	float jumpDelay;
	float speed;
	float moveDown = 24.0f;
	bool  isSpawning;
	bool  isLeaping;
	bool  isMoving;
	bool  landOnBlack;
	FVector leapDestination;
	FVector newDestination;
	FVector leapOfDeath;

	UPaperSpriteComponent* RedBallSpriteComponent;
	UPaperSprite *RedBallSpriteGround;
	UPaperSprite *RedBallSpriteJump;

	FVector spawnLocation;

	UAudioComponent* jumpSoundComponent;
	USoundCue*       jumpSound;


	void JumpToCubeTimer(float deltaTime);
	void DownRight();
	void DownLeft();

	//Execute small leap to look like we are jumping to a cube and not sliding to it
	void leapToCube(float deltaTime);

	//Execute movement to final destination (land on cube)
	void MovingToCube(float deltaTime);

	//Execute death leap if we jump off the piramid of cubes
	void deathJump(float deltaTime);
	
};
