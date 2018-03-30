// Fill out your copyright notice in the Description page of Project Settings.

#include "DummyInputPawn.h"


// Sets default values
ADummyInputPawn::ADummyInputPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADummyInputPawn::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, 0.0f, 0.0f));
	//Getting the Mani Menu HUD from the world
	if (GetWorld())
	{
		MainMenuHUD = Cast<AMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());            
	}
		
}

// Called every frame
void ADummyInputPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADummyInputPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("LeaderBoard", IE_Pressed, this, &ADummyInputPawn::CallLeaderBoardHUD);
	PlayerInputComponent->BindAction("StartGame", IE_Pressed, this, &ADummyInputPawn::StartGame);
	PlayerInputComponent->BindAction("ExitGame", IE_Pressed, this, &ADummyInputPawn::ExitGame);

}

void ADummyInputPawn::CallLeaderBoardHUD()
{
	UE_LOG(LogTemp, Warning, TEXT("LeaderBoard Input"));
	MainMenuHUD->ShowLeaderBoard();
}

void ADummyInputPawn::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Game"));

	if (GetWorld())
	{
		UGameplayStatics::OpenLevel(GetWorld(), "MainLevel"); // change level to level name
	}

}

void ADummyInputPawn::ExitGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Exit Game"));
	if (GetWorld())
	{
		GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");// Invokes quit game
	}
}