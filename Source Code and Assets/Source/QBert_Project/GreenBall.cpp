// Fill out your copyright notice in the Description page of Project Settings.

#include "GreenBall.h"


// Sets default values
AGreenBall::AGreenBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("GreenBallRoot")); //We attach the components to this root
	}

	GreenBallSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GreenBallSpriteComponent")); // Visual sprite representation
	GreenBallSpriteComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UPaperSprite> GreenBallSpriteGroundAsset(TEXT("/Game/QBertFolders/Sprites/PowerUP_and_Discs/GreenBallGround.GreenBallGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> GreenBallSpriteJumpAsset(TEXT("/Game/QBertFolders/Sprites/PowerUP_and_Discs/GreenBallJump.GreenBallJump"));

	GreenBallSpriteGround = GreenBallSpriteGroundAsset.Object;
	GreenBallSpriteJump = GreenBallSpriteJumpAsset.Object;

	GreenBallSpriteComponent->SetSprite(GreenBallSpriteGround);


	//Jump Sound setup
	jumpSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("JumpSoundComponent"));
	jumpSoundComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundCue> jumpSoundAsset(TEXT("/Game/QBertFolders/Sounds/BallJumpSound_Cue.BallJumpSound_Cue"));
	jumpSound = jumpSoundAsset.Object;
	jumpSoundComponent->bAutoActivate = false; // Stop if from playing when is created
	jumpSoundComponent->SetSound(jumpSound);


	//clock to measure jump time
	clockToJump = 0.0f;
	jumpDelay = 0.5f;

	//Movement speed
	speed = 100.0f;
	isMoving = false;
	isLeaping = false;
	landOnBlack = false;
	isSpawning = true;

	int LeftOrRight = FMath::RandRange(0, 100);

	if (LeftOrRight < 50)
	{
		spawnLocation = FVector(-16.0f, 2.0f, 237.0f);
		PositionIndexRow = 2;
		PositionIndexCol = 6;
	}
	else
	{
		spawnLocation = FVector(16.0f, 2.0f, 237.0f);
		PositionIndexRow = 2;
		PositionIndexCol = 8;
	}
}

// Called when the game starts or when spawned
void AGreenBall::BeginPlay()
{
	Super::BeginPlay();
	GreenBallSpriteComponent->SetSprite(GreenBallSpriteJump);
	
}

// Called every frame
void AGreenBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isSpawning)
	{
		isMoving = true;
		newDestination = spawnLocation;
	}

	if (landOnBlack)
	{
		deathJump(DeltaTime);
	}

	if (!landOnBlack)
	{
		if (!isMoving)
		{
			JumpToCubeTimer(DeltaTime);
		}

		if (isMoving && isLeaping)
		{
			leapToCube(DeltaTime);
		}

		if (isMoving && !isLeaping)
		{
			MovingToCube(DeltaTime);
		}
	}


}

void AGreenBall::JumpToCubeTimer(float deltaTime)
{
	clockToJump += deltaTime;

	if (clockToJump >= jumpDelay)
	{
		//Get Random number to decide which direction we are going.
		int LeftOrRight = FMath::RandRange(0, 100);

		if (LeftOrRight < 50)
		{
			clockToJump = 0.0f;
			DownLeft();
		}
		else
		{
			clockToJump = 0.0f;
			DownRight();
		}
	}
}




void AGreenBall::DownRight()
{
	if (!isMoving)
	{
		//Get actor location to update with the new values
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector(currentPosition.X + 8.0f, currentPosition.Y, currentPosition.Z + 4.0f);

		newDestination = FVector(currentPosition.X + 16.0f, currentPosition.Y, currentPosition.Z - 24.0f);

		isLeaping = true;
		isMoving = true;

		//lookAtDir = 3;
		GreenBallSpriteComponent->SetSprite(GreenBallSpriteJump);

		PositionIndexRow++;
		PositionIndexCol++;

		//blockValue = WorldGameMode->MapPosition(PositionIndexRow, PositionIndexCol);
		//UE_LOG(LogTemp, Warning, TEXT("BlockValue %d"), blockValue);

	}
}


void AGreenBall::DownLeft()
{
	if (!isMoving)
	{
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector(currentPosition.X - 8.0f, currentPosition.Y, currentPosition.Z + 4.0f);

		newDestination = FVector(currentPosition.X - 16.0f, currentPosition.Y, currentPosition.Z - 24.0f);

		isLeaping = true;
		isMoving = true;
		//lookAtDir = 1;
		GreenBallSpriteComponent->SetSprite(GreenBallSpriteJump);

		PositionIndexRow++;
		PositionIndexCol--;

	}
}

void AGreenBall::leapToCube(float deltaTime)
{
	FVector playerLocation = GetActorLocation();

	float distance = FVector::Distance(playerLocation, leapDestination);

	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 1.5f)
	{
		SetActorLocation(leapDestination);
		isLeaping = false;
	}

	//Get Direction towards the new position
	FVector Direction = leapDestination - playerLocation;
	//Normalize direction
	Direction.Normalize();
	//Multiply Speed and delta time to normalized direction to add movement
	Direction *= speed * deltaTime;
	//add the movement to the player location
	Direction += playerLocation;
	//Set the new position for the player
	SetActorLocation(Direction);

}

void AGreenBall::MovingToCube(float deltaTime)
{
	FVector playerLocation = GetActorLocation();

	float distance = FVector::Distance(playerLocation, newDestination);

	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 1.5f)
	{
		SetActorLocation(newDestination);

		if (PositionIndexRow > 7)
		{
			leapOfDeath = FVector(playerLocation.X, playerLocation.Y, playerLocation.Z - 500.0f);
			landOnBlack = true;
		}
		else
		{
			isMoving = false;
			isSpawning = false;
			jumpSoundComponent->Play();
			//Set Sprite
			GreenBallSpriteComponent->SetSprite(GreenBallSpriteGround);
			return;      // If we are at location end here
		}

	}

	//Get Direction towards the new position
	FVector Direction = newDestination - playerLocation;
	//Normalize direction
	Direction.Normalize();
	//Multiply Speed and delta time to normalized direction to add movement
	Direction *= speed * deltaTime;
	//add the movement to the player location
	Direction += playerLocation;
	//Set the new position for the player
	SetActorLocation(Direction);

}

void AGreenBall::deathJump(float deltaTime)
{
	FVector playerLocation = GetActorLocation();

	float distance = FVector::Distance(playerLocation, leapOfDeath);

	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 50.0f)
	{
		SetActorLocation(leapOfDeath);
		landOnBlack = false;
		Destroy(true);
	}

	//Get Direction towards the new position
	FVector Direction = leapOfDeath - playerLocation;
	//Normalize direction
	Direction.Normalize();
	//Multiply Speed and delta time to normalized direction to add movement
	Direction *= speed * deltaTime;
	//add the movement to the player location
	Direction += playerLocation;
	//Set the new position for the player
	SetActorLocation(Direction);
}

