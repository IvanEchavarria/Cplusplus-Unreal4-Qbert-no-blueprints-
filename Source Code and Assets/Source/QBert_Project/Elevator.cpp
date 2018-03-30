// Fill out your copyright notice in the Description page of Project Settings.

#include "Elevator.h"


// Sets default values
AElevator::AElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ElevatorRoot")); //We attach the components to this root 
	}

	//Set Component for Player Text UI and Animation
	ElevatorComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("ElevatorComponentComponent"));
	ElevatorComponent->SetupAttachment(RootComponent);
	//ConstructorHelpers can only be use in the constructor
	ConstructorHelpers::FObjectFinder<UPaperFlipbook> ElevatorAnimationAsset(TEXT("/Game/QBertFolders/Sprites/PowerUP_and_Discs/Elevator1.Elevator1"));

	ElevatorAnimation = ElevatorAnimationAsset.Object;
	ElevatorComponent->SetFlipbook(ElevatorAnimation);

	//Jump Sound setup
	moveSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("moveSoundComponent"));
	moveSoundComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundCue> moveSoundAsset(TEXT("/Game/QBertFolders/Sounds/Ride_the_disk_Cue.Ride_the_disk_Cue"));
	moveSound = moveSoundAsset.Object;
	moveSoundComponent->bAutoActivate = false; // Stop if from playing when is created
	moveSoundComponent->SetSound(moveSound);

	//Value of the top platform position
	topOfPlatform = FVector(0.0f, 1.0f, 274.0f);

	//Movement speed
	speed = 100.0f;
	isMoving = false;
}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isMoving)
	{
		MovingToCube(DeltaTime);
	}
	
}

void AElevator::MovingToCube(float deltaTime)
{
	FVector playerLocation = GetActorLocation();

	float distance = FVector::Distance(playerLocation, topOfPlatform);

	//If the distance to the objective is less than a value then we stop moving and make sure our location is the same as the destination for accuracy
	if (distance <= 1.5f)
	{
		SetActorLocation(topOfPlatform);		
		isMoving = false;		
		return;      // If we are at location end here
	}

	//Get Direction towards the new position
	FVector Direction = topOfPlatform - playerLocation;
	//Normalize direction
	Direction.Normalize();
	//Multiply Speed and delta time to normalized direction to add movement
	Direction *= speed * deltaTime;
	//add the movement to the player location
	Direction += playerLocation;
	//Set the new position for the player
	SetActorLocation(Direction);

}

void AElevator::MoveElevator()
{

	isMoving = true;
	moveSoundComponent->Play();
}

void AElevator::DestroyElevator()
{
	UE_LOG(LogTemp, Warning, TEXT("Destroying disk?"));
	Destroy(true);
}