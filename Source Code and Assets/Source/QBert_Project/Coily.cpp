// Fill out your copyright notice in the Description page of Project Settings.

#include "Coily.h"


// Sets default values
ACoily::ACoily()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CoilyRoot")); //We attach the components to this root 
	}

	CoilySpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CoilySpriteComponent")); // Visual sprite representation
	CoilySpriteComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyBallGroundSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyBallGround.CoilyBallGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyBallJumpSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyBallJump.CoilyBallJump"));

	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyDownRightGroundSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyDownRightGround.CoilyDownRightGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyDownRightJumpSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyDownRightJump.CoilyDownRightJump"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyDownLeftGroundSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyDownLeftGround.CoilyDownLeftGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyDownLeftJumpSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyDownLeftJump.CoilyDownLeftJump"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyUpRightGroundSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyUpRightGround.CoilyUpRightGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyUpRightJumpSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyUpRightJump.CoilyUpRightJump"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyUpLeftGroundSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyUpLeftGround.CoilyUpLeftGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> CoilyUpLeftJumpSprite(TEXT("/Game/QBertFolders/Sprites/Enemies_And_Hazzards/CoilyUpLeftJump.CoilyUpLeftJump"));

	/*if (CoilyDownRightGroundSprite.Succeeded())
	{
		//GLog->Log("Loaded sprite inside if");		
		CoilySpriteComponent->SetSprite(CoilyDownRightGroundSprite.Object);
	}*/


	CoilyBallGround = CoilyBallGroundSprite.Object;
	CoilyBallJump = CoilyBallJumpSprite.Object;

	CoilyDownRightGround = CoilyDownRightGroundSprite.Object;
	CoilyDownRightJump = CoilyDownRightJumpSprite.Object;
	CoilyDownLeftGround = CoilyDownLeftGroundSprite.Object;
	CoilyDownLeftJump = CoilyDownLeftJumpSprite.Object;
	CoilyUpRightGround = CoilyUpRightGroundSprite.Object;
	CoilyUpRightJump = CoilyUpRightJumpSprite.Object;
	CoilyUpLeftGround = CoilyUpLeftGroundSprite.Object;
	CoilyUpLeftJump = CoilyUpLeftJumpSprite.Object;

	//Set Coily sprite at the begining of the game
	CoilySpriteComponent->SetSprite(CoilyBallJump);

	//Ball JumpSound
	static ConstructorHelpers::FObjectFinder<USoundCue> ballJumpSoundAsset(TEXT("/Game/QBertFolders/Sounds/PurpleBallJumpSound_Cue.PurpleBallJumpSound_Cue"));
	ballJumpSound = ballJumpSoundAsset.Object;

	//Jump Sound setup
	jumpSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("JumpSoundComponent"));
	jumpSoundComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundCue> jumpSoundAsset(TEXT("/Game/QBertFolders/Sounds/Coily_Hops_Cue.Coily_Hops_Cue"));
	jumpSound = jumpSoundAsset.Object;
	jumpSoundComponent->bAutoActivate = false; // Stop if from playing when is created
	jumpSoundComponent->SetSound(ballJumpSound);	

	//Over the edge sound setup
	OverEdgeComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("OverEdgeComponent"));;
	OverEdgeComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundCue> OverEdgeSoundAsset(TEXT("/Game/QBertFolders/Sounds/Coily_Over_the_edge_Cue.Coily_Over_the_edge_Cue"));
	OverEdgeSound = OverEdgeSoundAsset.Object;
	OverEdgeComponent->bAutoActivate = false;
	OverEdgeComponent->SetSound(OverEdgeSound);


	//Movement speed
	speed = 100.0f;
	isSpawning = true;
	isCoilyABall = true;
	isMoving = false;
	isLeaping = false;
	landOnBlack = false;

	//clock to measure jump time
	clockToJump = 0.0f;
	jumpDelay = 0.5f;

	int LeftOrRight = FMath::RandRange(0, 100);

	if (LeftOrRight < 50)
	{
		spawnLocation = FVector(-16.0f, 2.0f, 234.0f);
		PositionIndexRow = 2;
		PositionIndexCol = 6;
	}
	else
	{
		spawnLocation = FVector(16.0f, 2.0f, 234.0f);
		PositionIndexRow = 2;
		PositionIndexCol = 8;
	}
}

// Called when the game starts or when spawned
void ACoily::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoily::Tick(float DeltaTime)
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

//Receives Qberts position from the the game mode manager
void ACoily::updateQbertPosition(int row, int col)
{
	QbertPositionIndexRow = row;
	QbertPositionIndexCol = col;
}

//Timer to take action to jump
void ACoily::JumpToCubeTimer(float deltaTime)
{
	clockToJump += deltaTime;

	if (clockToJump >= jumpDelay)
	{
		if (isCoilyABall)
		{
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
		else
		{
			chooseDirectionTowardsQbert();
		}
				
	}
}

void ACoily::chooseDirectionTowardsQbert()
{
	//SET OF STATEMENTS TO MAKE A RANDOM DECISION BASED ON QBERTS POSITION

	//If Qbert is on the same row , and he is to the right, then we move to the right
	if (QbertPositionIndexRow == PositionIndexRow && QbertPositionIndexCol > PositionIndexCol)
	{
		if (PositionIndexRow == 7)
		{
			UpRight();
		}
		else
		{
			//Select a random direction to more right
			if (getRandomDirection() < 50)
			{
				DownRight();
			}
			else
			{
				UpRight();
			}
		}
		
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}
	//If Qbert is on the same row, and he is to the left, then we move to the left
	if (QbertPositionIndexRow == PositionIndexRow && QbertPositionIndexCol < PositionIndexCol)
	{
		if (PositionIndexRow == 7)
		{
			UpLeft();
		}
		else
		{
			if (getRandomDirection() < 50)
			{
				DownLeft();
			}
			else
			{
				UpLeft();
			}
		}		
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}
	//If Qbert is on the same colum, and he is below, then we move down
	if (QbertPositionIndexCol == PositionIndexCol && QbertPositionIndexRow > PositionIndexRow)
	{
		if (getRandomDirection() < 50)
		{
			DownLeft();
		}
		else
		{
			DownRight();
		}
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}

	//If Qbert is on the same colum, and he is above, then we move up
	if (QbertPositionIndexCol == PositionIndexCol && QbertPositionIndexRow < PositionIndexRow)
	{
		if (getRandomDirection() < 50)
		{
			UpLeft();
		}
		else
		{
			UpRight();
		}
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}

	//SET OF STATEMENTS TO MAKE A  ACCURATE DECISION BASED ON QBERTS POSITION

	//If Qbert is below us and to the right, we move down right
	if (QbertPositionIndexRow > PositionIndexRow && QbertPositionIndexCol > PositionIndexCol)
	{
		DownRight();
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}
	//If Qbert is Above us and to the right, we move up right
	if (QbertPositionIndexRow < PositionIndexRow && QbertPositionIndexCol > PositionIndexCol)
	{
		UpRight();
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}
	//If Qbert is below us and to the left, we move down left
	if (QbertPositionIndexRow > PositionIndexRow && QbertPositionIndexCol < PositionIndexCol)
	{
		DownLeft();
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}

	//If Qbert is above us and to the left, we move up left
	if (QbertPositionIndexRow < PositionIndexRow && QbertPositionIndexCol < PositionIndexCol)
	{
		UpLeft();
		jumpSoundComponent->Play();
		clockToJump = 0.0f;
		return;
	}

}

int ACoily::getRandomDirection()
{
	//Get Random number to decide which direction we are going.
	int chooseDirection = FMath::RandRange(0, 100);
	return chooseDirection;
}

void ACoily::DownRight()
{
	if (!isMoving)
	{
		//Get actor location to update with the new values
		FVector currentPosition = GetActorLocation();
		leapDestination = FVector(currentPosition.X + 8.0f, currentPosition.Y, currentPosition.Z + 4.0f);
		newDestination = FVector(currentPosition.X + 16.0f, currentPosition.Y, currentPosition.Z - 24.0f);
		isLeaping = true;
		isMoving = true;
		lookAtDir = 3;
		PositionIndexRow++;
		PositionIndexCol++;
		if (isCoilyABall)
		{
			CoilySpriteComponent->SetSprite(CoilyBallJump);
			jumpSoundComponent->Play();
		}
		else
		{
			CoilySpriteComponent->SetSprite(CoilyDownRightJump);
		}		
	}
}

void ACoily::DownLeft()
{
	if (!isMoving)
	{
		FVector currentPosition = GetActorLocation();
		leapDestination = FVector(currentPosition.X - 8.0f, currentPosition.Y, currentPosition.Z + 4.0f);
		newDestination = FVector(currentPosition.X - 16.0f, currentPosition.Y, currentPosition.Z - 24.0f);
		isLeaping = true;
		isMoving = true;
		lookAtDir = 1;
		PositionIndexRow++;
		PositionIndexCol--;
		if (isCoilyABall)
		{
			CoilySpriteComponent->SetSprite(CoilyBallJump);
			jumpSoundComponent->Play();
		}
		else
		{
			CoilySpriteComponent->SetSprite(CoilyDownLeftJump);
		}		
	}
}

void ACoily::UpRight()
{
	if (!isMoving)
	{
		FVector currentPosition = GetActorLocation();
		leapDestination = FVector(currentPosition.X + 14.0f, currentPosition.Y, currentPosition.Z + 32.0f);
		newDestination = FVector(currentPosition.X + 16.0f, currentPosition.Y, currentPosition.Z + 24.0f);
		isLeaping = true;
		isMoving = true;
		lookAtDir = 9;
		PositionIndexRow--;
		PositionIndexCol++;
		CoilySpriteComponent->SetSprite(CoilyUpRightJump);
	}
}

void ACoily::UpLeft()
{
	if (!isMoving)
	{
		FVector currentPosition = GetActorLocation();
		leapDestination = FVector(currentPosition.X - 14.0f, currentPosition.Y, currentPosition.Z + 32.0f);
		newDestination = FVector(currentPosition.X - 16.0f, currentPosition.Y, currentPosition.Z + 24.0f);
		isLeaping = true;
		isMoving = true;
		lookAtDir = 7;
		PositionIndexRow--;
		PositionIndexCol--;
		CoilySpriteComponent->SetSprite(CoilyUpLeftJump);
	}
}

//Small leap to destination to create the illusion of jumping ahead and gravity
void ACoily::leapToCube(float deltaTime)
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

void ACoily::MovingToCube(float deltaTime)
{
	FVector CoilyLocation = GetActorLocation();

	float distance = FVector::Distance(CoilyLocation, newDestination);

	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 1.5f)
	{
		if (PositionIndexRow == 7 && isCoilyABall)
		{
			isCoilyABall = false;
			jumpSoundComponent->SetSound(jumpSound);
			newDestination.Z += 4.0f;
			SetActorLocation(newDestination);
		}
		else if (PositionIndexRow > 7)
		{
			leapOfDeath = FVector(CoilyLocation.X, CoilyLocation.Y, CoilyLocation.Z - 500.0f);
			landOnBlack = true;
			OverEdgeComponent->Play();
		}
		else
		{
			isSpawning = false;
			isMoving = false;
			SetActorLocation(newDestination);

			if (isCoilyABall)
			{
				CoilySpriteComponent->SetSprite(CoilyBallGround);
			}
			else
			{
				//Set Sprite for snake coily
				switch (lookAtDir)
				{
				case 3:
					CoilySpriteComponent->SetSprite(CoilyDownRightGround);
					break;
				case 1:
					CoilySpriteComponent->SetSprite(CoilyDownLeftGround);
					break;
				case 9:
					CoilySpriteComponent->SetSprite(CoilyUpRightGround);
					break;
				case 7:
					CoilySpriteComponent->SetSprite(CoilyUpLeftGround);
					break;
				}
			}			
			return;
		}				
		
		
	}
	
	//Get Direction towards the new position
	FVector Direction = newDestination - CoilyLocation;
	//Normalize direction
	Direction.Normalize();
	//Multiply Speed and delta time to normalized direction to add movement
	Direction *= speed * deltaTime;
	//add the movement to the player location
	Direction += CoilyLocation;
	//Set the new position for the player
	SetActorLocation(Direction);

}


void ACoily::deathJump(float deltaTime)
{
	FVector playerLocation = GetActorLocation();

	float distance = FVector::Distance(playerLocation, leapOfDeath);

	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 1.5f)
	{
		SetActorLocation(leapOfDeath);
		//landOnBlack = false;
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