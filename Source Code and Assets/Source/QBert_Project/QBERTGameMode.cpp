// Fill out your copyright notice in the Description page of Project Settings.

#include "QBERTGameMode.h"
//#include "Cube.h" // include Cube h to use the class

AQBERTGameMode::AQBERTGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	world = GetWorld();	
	TopCube = 274.0f;
	MostLeftCube = 0.0f;
	RightSideCube = 0.0f;
	clockRedBallSpawn = 0.0f;
	clockGreenBallSpawn = 0.0f;
	clockCoilySpawn = 0.0f;

	CubesLeftActive = 0; // No cubes have been created we start with zero cubes active

	//Setup the default pawn to static class
	//DefaultPawnClass = AQBERTGameMode::StaticClass();
	//PlayerControllerClass = ^ same as above
	//Find me a class with this constructor helper
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawn(TEXT("/Script/QBert_Project.Qbert"));
	DefaultPawnClass = PlayerPawn.Class;

}


void AQBERTGameMode::MapGenerator()
{
	//On Screen Debug for everything
	/*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf
		(TEXT("Current TopCube Value %f"), TopCube));*/

	for (int row = 0; row < numberOfRows; row++)
	{
		LevelReference = row;
		RightSideCube = MostLeftCube;
	    //GLog->Log("ROW LOOP"); String only debug
		
		for (int col = 0; col < numberOfCols; col++)
		{
			if (mapLayout[row][col] == 0 || mapLayout[row][col] == 3)
			{
				mapArray[row][col] = nullptr;
			}
			if (mapLayout[row][col] == 1)
			{
				if (world)
				{
					//GLog->Log(TopCube);
					if (LevelReference == row) // Check the level reference if it is the same then move to the new level an position the left most cube
					{
						MostLeftCube -= 16.0f;
						TopCube = TopCube - 24.0f;
						LevelReference++;
					}
					else
					{
						RightSideCube += 32.0f;

					}
					FActorSpawnParameters sParams;
					sParams.Owner = NULL;
					FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
					FVector location = FVector(RightSideCube, 0.0f, TopCube);

					if (ACube* newCube = world->SpawnActor<ACube>((tempCube, location, rotator, sParams)))
					{
						mapArray[row][col] = newCube;
						mapArray[row][col]->SetActorLocation(location);
						CubesLeftActive++;
					}
				}

			}

		}
	}

}

void AQBERTGameMode::SetupUI()
{
	FActorSpawnParameters sParams;
	sParams.Owner = NULL;
	FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
	FVector location = FVector(-80.0f, 2.0f, 300.0f);

	if (AUIElements* newUI = world->SpawnActor<AUIElements>((tempUI, location, rotator, sParams)))
	{
		UserInterFaceObj = newUI;
		UserInterFaceObj->SetActorLocation(location);
	}
	
}

void AQBERTGameMode::AddEnemies()
{
	FActorSpawnParameters sParams;
	sParams.Owner = NULL;
	FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
	FVector location = FVector(0.0f, 2.0f, 0.0f);

	if (ARedBall* newRedBall = world->SpawnActor<ARedBall>(location, rotator, sParams))
	{
		if (redBallCounter == 0)
		{
			EnemyRedBallObj = newRedBall;
			location.Z += mapArray[2][6]->GetActorLocation().Z + 300.0f;
			EnemyRedBallObj->SetActorLocation(location);
			redBallCounter++;
		}
		else if (redBallCounter >= 1)
		{
			EnemyRedBallObjTwo = newRedBall;
			location.Z += mapArray[2][6]->GetActorLocation().Z + 300.0f;
			EnemyRedBallObjTwo->SetActorLocation(location);
			redBallCounter = 0;
		}	
		
	}

}

void AQBERTGameMode::AddPowerUps()
{
	FActorSpawnParameters sParams;
	sParams.Owner = NULL;
	FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
	FVector location = FVector(16.0f, 2.0f, 537.0f);

	if (AGreenBall* newGreenBall = world->SpawnActor<AGreenBall>(location, rotator, sParams))
	{
		AidGreenBallObj = newGreenBall;
		AidGreenBallObj->SetActorLocation(location);
	}
}

void AQBERTGameMode::AddElevators()
{
	FActorSpawnParameters sParams;
	sParams.Owner = NULL;
	FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
	FVector location = FVector(-79.0f, 0.0f, 182.0f);

	if (AElevator* newElevator = world->SpawnActor<AElevator>(location, rotator, sParams))
	{
		ElevatorObj = newElevator;
		ElevatorObj->SetActorLocation(location);
	}

	location = FVector(79.0f, 0.0f, 182.0f);

	if (AElevator* newElevator = world->SpawnActor<AElevator>(location, rotator, sParams))
	{
		ElevatorObj2 = newElevator;
		ElevatorObj2->SetActorLocation(location);
	}

}

void AQBERTGameMode::SpawnCoily()
{
	FActorSpawnParameters sParams;
	sParams.Owner = NULL;
	FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
	//FVector location = FVector(1.0f, 2.0f, 215.0f);
	FVector location = FVector(1.0f, 2.0f, 515.0f);

	if (ACoily* newCoily = world->SpawnActor<ACoily>(location, rotator, sParams))
	{
		CoilyObj = newCoily;
		CoilyObj->SetActorLocation(location);
	}
}

int AQBERTGameMode::MapPosition(int row, int col)
{
	if (mapLayout[row][col] == 0)
	{
		return mapLayout[row][col];
	}
	else if (mapLayout[row][col] == 1)
	{
		if (mapArray[row][col]->isCubeActive())
		{
			mapArray[row][col]->setNewSprite();
			CubesLeftActive--;
			//UE_LOG(LogTemp, Warning, TEXT("BlockValue %d"), CubesLeftActive);
			return mapLayout[row][col];
		}		
	}
	else if (mapLayout[row][col] == 4)
	{
		mapLayout[row][col] = 0;
		return 4;
	}

	
	return 1;
}



// Called when the game starts or when spawned
void AQBERTGameMode::BeginPlay()
{
	Super::BeginPlay();
	MapGenerator();
	SetupUI();
	SpawnCoily();
	AddElevators();	
}

// Called every frame
void AQBERTGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	clockRedBallSpawn += DeltaTime;
	clockGreenBallSpawn += DeltaTime;


	if (clockRedBallSpawn >= 3.0f)
	{
		AddEnemies();
		clockRedBallSpawn = 0.0f;
	}

	if (clockGreenBallSpawn >= 25.0f)
	{
		AddPowerUps();
		clockGreenBallSpawn = 0.0f;
	}

}

//Receives Qberts position in the array, to pass it to coily so coily can track him down.
void AQBERTGameMode::receiveQbertPosition(int row, int col)
{
	CoilyObj->updateQbertPosition(row, col);
}

//Will be called when player pauses the game receiving input from Qbert
void AQBERTGameMode::activatePauseOptions(bool isPaused)
{
	UserInterFaceObj->showPausedOptions(isPaused);
}

//Called by Qbert when he is riding the elevator
void AQBERTGameMode::QbertIsOnElevator(int col)
{
	ElevatorChosen = col;

	if (col < 7)
	{		
		ElevatorObj->MoveElevator();
	}
	else
	{		
		ElevatorObj2->MoveElevator();
	}
	
}

//Called by Qbert once he has reached the top of the pyramid
void AQBERTGameMode::callElevatorDestruction()
{
	
	UE_LOG(LogTemp, Warning, TEXT("Elevator Chosen %d"), ElevatorChosen);

	if (ElevatorChosen < 7)
	{
		ElevatorObj->DestroyElevator();
	}
	else
	{
		ElevatorObj2->DestroyElevator();
	}
}