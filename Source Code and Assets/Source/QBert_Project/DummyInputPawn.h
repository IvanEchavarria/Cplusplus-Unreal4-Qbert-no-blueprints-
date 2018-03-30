// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "MainMenuHUD.h"
#include "CoreMisc.h"
#include "GameFramework/Pawn.h"
#include "DummyInputPawn.generated.h"

UCLASS()
class QBERT_PROJECT_API ADummyInputPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADummyInputPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	AMainMenuHUD* MainMenuHUD;

	// Input actions to move the player
	void CallLeaderBoardHUD();
	void StartGame();
	void ExitGame();
	
};
