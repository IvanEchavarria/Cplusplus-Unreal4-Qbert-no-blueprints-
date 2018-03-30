// Fill out your copyright notice in the Description page of Project Settings.

#include "Cube.h"
//#include "PaperSpriteComponent.h"
//#include "PaperSprite.h"

// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CubeRoot")); //We attach the components to this root 
	}
	
	CubeSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CubeSprite"));
	CubeSprite->SetupAttachment(RootComponent);
	//ConstructorHelpers can only be use in the constructor
	ConstructorHelpers::FObjectFinder<UPaperSprite> CubeVisualSprite(TEXT("/Game/QBertFolders/Sprites/Cubes/GreenCubes/Yellow.Yellow"));

	if (CubeVisualSprite.Succeeded())
	{
		CubeSprite->SetSprite(CubeVisualSprite.Object);
	}

	static ConstructorHelpers::FObjectFinder<UPaperSprite> BlueCubeSprite(TEXT("/Game/QBertFolders/Sprites/Cubes/GreenCubes/Purple.Purple"));

	BlueCube = BlueCubeSprite.Object;

	isActive = true;
}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
/*void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

bool ACube::isCubeActive()
{
	return isActive;
}

void ACube::setNewSprite()
{
	//Loads object if the object has not been loaded by the engine, can cause lag spikes if too many objects are loaded at the time.
	//Auto just creates a type of whatever it receives, seems not to be appreciated.
	//auto CubeVisualSprite = LoadObject<UPaperSprite> (NULL,TEXT("/Game/QBertFolders/Sprites/Cubes/GreenCubes/Purple.Purple"),NULL, LOAD_None, NULL); use this to load at runtime object not found tho.
	CubeSprite->SetSprite(BlueCube);
	isActive = false;
}
