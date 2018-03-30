// Fill out your copyright notice in the Description page of Project Settings.

#include "Qbert.h"

class UPaperSprite;
// Sets default values
AQbert::AQbert()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;

	//Root parent component that holds all the components of an object, when asking for a rotation, translation, position of an object we use the RootComponent to get that info
	//USceneComponent posses position, rotation of an object without collission or geometry
	//TEXT is a macro used to pass strings ( recommended) it doesnt have to match anything
	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("QbertRoot")); //We attach the components to this root 
	}


	QbertSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("QberSprite")); // Visual sprite representation
	QbertSprite->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertDownRightGroundSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertDownRightGround.QbertDownRightGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertDownRightJumpSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertDownRightJump.QbertDownRightJump"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertDownLeftGroundSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertDownLeftGround.QbertDownLeftGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertDownLeftJumpSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertDownLeftJump.QbertDownLeftJump"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertUpRightGroundSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertUpRightGround.QbertUpRightGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertUpRightJumpSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertUpRightJump.QbertUpRightJump"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertUpLeftGroundSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertUpLeftGround.QbertUpLeftGround"));
	static ConstructorHelpers::FObjectFinder<UPaperSprite> QbertUpLeftJumpSprite(TEXT("/Game/QBertFolders/Sprites/Qbert/QbertUpLeftJump.QbertUpLeftJump"));

	if (QbertDownRightGroundSprite.Succeeded())
	{
		//GLog->Log("Loaded sprite inside if");		
		QbertSprite->SetSprite(QbertDownRightGroundSprite.Object);
	}
	
	QbertDownRightGround = QbertDownRightGroundSprite.Object;
	QbertDownRightJump = QbertDownRightJumpSprite.Object;
	QbertDownLeftGround = QbertDownLeftGroundSprite.Object;
	QbertDownLeftJump = QbertDownLeftJumpSprite.Object;
	QbertUpRightGround = QbertUpRightGroundSprite.Object;
	QbertUpRightJump = QbertUpRightJumpSprite.Object;
	QbertUpLeftGround = QbertUpLeftGroundSprite.Object;
	QbertUpLeftJump = QbertUpLeftJumpSprite.Object;

	//Sound Setup
	//Jump Sound setup
	jumpSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("JumpSoundComponent"));
	jumpSoundComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundCue> jumpSoundAsset(TEXT("/Game/QBertFolders/Sounds/QbertJumpCue.QbertJumpCue"));
	jumpSound = jumpSoundAsset.Object;
	jumpSoundComponent->bAutoActivate = false; // Stop if from playing when is created
	jumpSoundComponent->SetSound(jumpSound);

	//Over the edge sound setup
	OverEdgeComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("OverEdgeComponent"));;
	OverEdgeComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundCue> OverEdgeSoundAsset(TEXT("/Game/QBertFolders/Sounds/OverTheEdgeCue.OverTheEdgeCue"));
	OverEdgeSound = OverEdgeSoundAsset.Object;
	OverEdgeComponent->bAutoActivate = false;
	OverEdgeComponent->SetSound(OverEdgeSound);
	
	//At moment of creation setActorLocation will take the offset (If any) of each axis, therefore it will add the numbers to the actual numbers that the object has at moment of creation
	//No set location here	
	
	//Movement speed
	speed = 100.0f;
	unPauseClock = 0.0f;
	landOnBlack = false;
	isMoving = false;
	isLeaping = false;
	pauseGame = false;

	//Value of the top platform position
	topOfPlatform = FVector(0.0f, 1.0f, 285.0f);
	//is Qbert on an Elevator
	isOnElevator = false;
}

// Called when the game starts or when spawned
void AQbert::BeginPlay()
{
	Super::BeginPlay();
	//Set Actor Location on game start
	SetActorLocation(FVector(1.0f, 1.0f, 263.0f));

	if (GetWorld())
	{
		WorldGameMode = (AQBERTGameMode*)GetWorld()->GetAuthGameMode();
		//Get Hold of player controller
		playerController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	}
}

// Called every frame
void AQbert::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Returns true if the given key/button is pressed on the input of the controller (if present)
	if (playerController->IsInputKeyDown(FKey("U")))
	{
		pauseGame = false;
		playerController->SetPause(false);  // Unpause game by pressing U key
		WorldGameMode->activatePauseOptions(false);
		
	}
	//magic magic pewpew (ivan if you delete we will have a war)!!!
	if (pauseGame)
	{
		if (playerController->IsInputKeyDown(FKey("Q")))
		{
			//Call exit game to go to the main menu
			ExitGame();
		}
	}

	if (isOnElevator)
	{
		isMoving = true;		
	}
	
	if (landOnBlack)
	{
		deathJump(DeltaTime);
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

// Called to bind functionality to input
void AQbert::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("DownLeft", IE_Pressed, this, &AQbert::DownLeft);
	PlayerInputComponent->BindAction("DownRight", IE_Pressed, this, &AQbert::DownRight);
	PlayerInputComponent->BindAction("UpLeft", IE_Pressed, this, &AQbert::UpLeft);
	PlayerInputComponent->BindAction("UpRight", IE_Pressed, this, &AQbert::UpRight);
	PlayerInputComponent->BindAction("PauseGame", IE_Pressed, this, &AQbert::Pausegame);
}

//Pause Game function
void AQbert::Pausegame()
{
	pauseGame = true;
	playerController->SetPause(true);
	WorldGameMode->activatePauseOptions(true);
}

//Exit game to main menu
void AQbert::ExitGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Exit Game"));

	if (GetWorld())
	{
		UGameplayStatics::OpenLevel(GetWorld(), "MainMenu"); // change level to level name
	}	
}

void AQbert::DownRight()
{	
	if (!isMoving && !landOnBlack)
	{
		//Get actor location to update with the new values
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector(currentPosition.X + 8.0f, currentPosition.Y, currentPosition.Z + 4.0f);

		newDestination = FVector(currentPosition.X + 16.0f, currentPosition.Y, currentPosition.Z - 24.0f);

		isLeaping = true;
		isMoving = true;

		lookAtDir = 3;
		QbertSprite->SetSprite(QbertDownRightJump);

		PositionIndexRow++;
		PositionIndexCol++;	

		//Transfer updated position to the world game mode
		WorldGameMode->receiveQbertPosition(PositionIndexRow, PositionIndexCol);
		
		//blockValue = WorldGameMode->MapPosition(PositionIndexRow, PositionIndexCol);
		//UE_LOG(LogTemp, Warning, TEXT("BlockValue %d"), blockValue);
		
	}	
}

void AQbert::DownLeft()
{
	
	if (!isMoving && !landOnBlack)
	{
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector(currentPosition.X - 8.0f, currentPosition.Y, currentPosition.Z + 4.0f);

		newDestination = FVector(currentPosition.X - 16.0f, currentPosition.Y, currentPosition.Z - 24.0f);

		isLeaping = true;
		isMoving = true;
		lookAtDir = 1;
		QbertSprite->SetSprite(QbertDownLeftJump);

		PositionIndexRow++;
		PositionIndexCol--;

		//Transfer updated position to the world game mode
		WorldGameMode->receiveQbertPosition(PositionIndexRow, PositionIndexCol);
		
	}
}

void AQbert::UpRight()
{
	if (!isMoving && !landOnBlack)
	{
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector(currentPosition.X + 14.0f, currentPosition.Y, currentPosition.Z + 32.0f);

		newDestination = FVector(currentPosition.X + 16.0f, currentPosition.Y, currentPosition.Z + 24.0f);

		isLeaping = true;
		isMoving = true;
		lookAtDir = 9;
		QbertSprite->SetSprite(QbertUpRightJump);

		PositionIndexRow--;
		PositionIndexCol++;

		//Transfer updated position to the world game mode
		WorldGameMode->receiveQbertPosition(PositionIndexRow, PositionIndexCol);

	}
}

void AQbert::UpLeft()
{
	if (!isMoving && !landOnBlack)
	{
		FVector currentPosition = GetActorLocation();

		leapDestination = FVector(currentPosition.X - 14.0f, currentPosition.Y, currentPosition.Z + 32.0f);

		newDestination = FVector(currentPosition.X - 16.0f, currentPosition.Y, currentPosition.Z + 24.0f);

		isLeaping = true;
		isMoving = true;
		lookAtDir = 7;
		QbertSprite->SetSprite(QbertUpLeftJump);

		PositionIndexRow--;
		PositionIndexCol--;

		//Transfer updated position to the world game mode
		WorldGameMode->receiveQbertPosition(PositionIndexRow, PositionIndexCol);

	}
}

void AQbert::leapToCube(float deltaTime)
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

void AQbert::MovingToCube(float deltaTime)
{
	FVector playerLocation = GetActorLocation();

	float distance = FVector::Distance(playerLocation, newDestination);
		
	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 1.5f)
	{		
		SetActorLocation(newDestination);
		blockValue = WorldGameMode->MapPosition(PositionIndexRow, PositionIndexCol);		
		
		if (isOnElevator && blockValue == 0)
		{
			//blockValue = 5;
			PositionIndexRow = 1;
			PositionIndexCol = 7;
			WorldGameMode->callElevatorDestruction();
			newDestination = FVector(1.0f, 1.0f, 263.0f);				
			//return;
		}
		else if (blockValue == 4 && !isOnElevator)
		{
			isOnElevator = true;
			newDestination = topOfPlatform;
			WorldGameMode->QbertIsOnElevator(PositionIndexCol);
		}
		else
		{
			if (blockValue == 0)
			{
				if (PositionIndexRow >= 7)
				{
					leapOfDeath = FVector(playerLocation.X, playerLocation.Y, playerLocation.Z - 500.0f);
				}
				else
				{
					playerLocation = GetActorLocation();
					playerLocation.Y = -1.0f;
					SetActorLocation(playerLocation);
					leapOfDeath = FVector(playerLocation.X, playerLocation.Y, playerLocation.Z - 500.0f);
				}
				OverEdgeComponent->Play();
				landOnBlack = true;
			}

			isOnElevator = false;
			isMoving = false;
			jumpSoundComponent->Play();
			//Set Sprite
			switch (lookAtDir)
			{
			case 3:
				QbertSprite->SetSprite(QbertDownRightGround);
				break;
			case 1:
				QbertSprite->SetSprite(QbertDownLeftGround);
				break;
			case 9:
				QbertSprite->SetSprite(QbertUpRightGround);
				break;
			case 7:
				QbertSprite->SetSprite(QbertUpLeftGround);
				break;
			}
			return;
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

void AQbert::deathJump(float deltaTime)
{
	FVector playerLocation = GetActorLocation();

	float distance = FVector::Distance(playerLocation, leapOfDeath);

	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 1.5f)
	{
		SetActorLocation(leapOfDeath);
		landOnBlack = false;
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
