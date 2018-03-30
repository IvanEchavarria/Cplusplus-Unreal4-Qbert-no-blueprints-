// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Cube.h"
#include "UIElements.h"
#include "RedBall.h"
#include "GreenBall.h"
#include "Elevator.h"
#include "Coily.h"
#include "QBERTGameMode.generated.h"

/**
 * 
 */
//class ARedBall;     //RedBall Enemy
class AUIElements; // User interface object
class ACube; // Let this know what a ACube class is

UCLASS()
class QBERT_PROJECT_API AQBERTGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AQBERTGameMode();
	int  MapPosition(int row, int col);
	void receiveQbertPosition(int row, int col); //Get Qberts position in the array to pass to coily
	void activatePauseOptions(bool isPaused);
	//Is Qbert Riding like a boss
	void QbertIsOnElevator(int col);
	//Destroy elevator after it has reached destination
	void callElevatorDestruction();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:	
	//Counter for how many cubes we have left to convert
	int  CubesLeftActive;

	//Variables for cube position in the world
	float TopCube;
	float MostLeftCube;
	float RightSideCube;
	int   LevelReference;

	// Qberts position row and colum in the array.
	int QbertPositionIndexRow;
	int QbertPositionIndexCol;

	//World reference
	UWorld *world;

	//Object containing all the ui of the level
	AUIElements *UserInterFaceObj;

	//Enemy spawn Clock
	float clockRedBallSpawn;

	//Green ball spawn clock
	float clockGreenBallSpawn;

	// Coily Spawn Clock
	float clockCoilySpawn;

	//Counter for redballs
	int redBallCounter = 0;

	//Enemies and power ups
	ARedBall     *EnemyRedBallObj;
	ARedBall     *EnemyRedBallObjTwo;
	AGreenBall	 *AidGreenBallObj;
	AElevator    *ElevatorObj;
	int           ElevatorChosen;
	ACoily		 *CoilyObj;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Elevators", meta = (AllowPrivateAccess = "true"))
	AElevator	 *ElevatorObj2;


	//This Subclasses are not necessary to spawn the actors
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AUIElements> tempUI;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cube", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ACube> tempCube;
	//AActor in this means spawn any actor;
	//ACube to spawn a cube class actor
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "World Array", meta = (AllowPrivateAccess = "true"))
	int numberOfRows = 9;
	int numberOfCols = 15;

						   // 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
	int mapLayout[9][15] = {{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },  //0
							{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },  //1
							{ 0 , 0 , 0 , 0 , 0 , 0 , 1 , 3 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },  //2
							{ 0 , 0 , 0 , 0 , 0 , 1 , 3 , 1 , 3 , 1 , 0 , 0 , 0 , 0 , 0 },  //3
							{ 0 , 0 , 4 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 4 , 0 , 0 },  //4
							{ 0 , 0 , 0 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 0 , 0 , 0 },  //5
							{ 0 , 0 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 0 , 0 },  //6
							{ 0 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 3 , 1 , 0 },  //7
							{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } };//8;
	//Array holder to pass the map information									
	ACube *mapArray[9][15];
	//Generate map add cubes to it in the proper position bases in the maplayout
	void MapGenerator();
	//Add the UI object to the world that contains score lives level etc
	void SetupUI();
	//Add enemies red ball, purple ball, purple enemies
	void AddEnemies();
	//Adds green balls that are qberts powerups to stop time
	void AddPowerUps();
	//Add elevator objects to the world
	void AddElevators();
	//Adds coily object to the world
	void SpawnCoily();
	

};
