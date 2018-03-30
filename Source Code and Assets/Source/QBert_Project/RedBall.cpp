// Fill out your copyright notice in the Description page of Project Settings.

#include "RedBall.h"


// Sets default values
ARedBall::ARedBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RedBallRoot")); //We attach the components to this root
	}

	RedBallSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("RedBallSpriteComponent")); // Visual sprite representation
	RedBallSpriteComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UPaperSprite> RedBallSpriteGroundAsset(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/RedBallGround.RedBallGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> RedBallSpriteJumpAsset(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/RedBallJump.RedBallJump"));

	RedBallSpriteGround = RedBallSpriteGroundAsset.Object;
	RedBallSpriteJump = RedBallSpriteJumpAsset.Object;

	RedBallSpriteComponent->SetSprite(RedBallSpriteGround);

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
	isSpawning = true;
	isMoving = false;
	isLeaping = false;
	landOnBlack = false;

	int LeftOrRight = FMath::RandRange(0, 100);

	if (LeftOrRight < 50)
	{
		spawnLocation = FVector(-16.0f, 2.0f, 236.0f);
		PositionIndexRow = 2;
		PositionIndexCol = 6;
	}
	else
	{
		spawnLocation = FVector(16.0f, 2.0f, 236.0f);
		PositionIndexRow = 2;
		PositionIndexCol = 8;
	}
	

}

// Called when the game starts or when spawned
void ARedBall::BeginPlay()
{
	Super::BeginPlay();
	RedBallSpriteComponent->SetSprite(RedBallSpriteJump);
}

// Called every frame
void ARedBall::Tick(float DeltaTime)
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

void ARedBall::JumpToCubeTimer(float deltaTime)
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




void ARedBall::DownRight()
{
	if (!isMoving)
	{
		//Get actor location to update with the new values
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector((int)currentPosition.X + 8.0f, (int)currentPosition.Y, (int)currentPosition.Z + 4.0f);

		newDestination = FVector((int)currentPosition.X + 16.0f, (int)currentPosition.Y, (int)currentPosition.Z - moveDown);

		//moveDown -= 0.6f;

		isLeaping = true;
		isMoving = true;

		//lookAtDir = 3;
		RedBallSpriteComponent->SetSprite(RedBallSpriteJump);

		PositionIndexRow++;
		PositionIndexCol++;


		//blockValue = WorldGameMode->MapPosition(PositionIndexRow, PositionIndexCol);
		//UE_LOG(LogTemp, Warning, TEXT("BlockValue %d"), blockValue);

	}
}


void ARedBall::DownLeft()
{
	if (!isMoving)
	{
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector((int)currentPosition.X - 8.0f, (int)currentPosition.Y, (int)currentPosition.Z + 4.0f);

		newDestination = FVector((int)currentPosition.X - 16.0f, (int)currentPosition.Y, (int)currentPosition.Z - moveDown);

		//moveDown -= 0.6f;

		isLeaping = true;
		isMoving = true;
		//lookAtDir = 1;
		RedBallSpriteComponent->SetSprite(RedBallSpriteJump);

		PositionIndexRow++;
		PositionIndexCol--;

	}
}

void ARedBall::leapToCube(float deltaTime)
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

void ARedBall::MovingToCube(float deltaTime)
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
			RedBallSpriteComponent->SetSprite(RedBallSpriteGround);
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

void ARedBall::deathJump(float deltaTime)
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