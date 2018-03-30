// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Qbert_Project.h" // This class contains all the below headers that are commented out since they are being repeated on many other classes
//#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Engine.h"
#include "Cube.generated.h"

UCLASS()
class QBERT_PROJECT_API ACube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACube();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	void setNewSprite(); // Set a new sprite color to the cube
	bool isCubeActive(); // Return true if the cube hasnt been landed on, false if is already changed.

private:
	// Flag to check if the cube has been activated, if isActive = true, means it hasnt been landed on.
	bool isActive;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CubeType", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* CubeSprite;
	
	UPaperSprite *BlueCube;
};
