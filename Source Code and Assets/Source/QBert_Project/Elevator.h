// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Qbert_Project.h"
#include "GameFramework/Actor.h"
#include "Elevator.generated.h"

UCLASS()
class QBERT_PROJECT_API AElevator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevator();
	void MoveElevator();
	void DestroyElevator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Destination position for Elevator
	FVector topOfPlatform;

	//Movement variables
	float speed;
	bool  isMoving;

	//Sound component
	UAudioComponent* moveSoundComponent;
	USoundCue*       moveSound;

	//Execute movement to final destination (land on cube)
	void MovingToCube(float deltaTime);

	//Animation assets of the elevator
	UPaperFlipbookComponent* ElevatorComponent;
	UPaperFlipbook*			 ElevatorAnimation;
	
};
