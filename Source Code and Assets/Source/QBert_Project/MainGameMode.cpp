// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"


AMainGameMode::AMainGameMode()
{
	//Activate tick
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MainGameModeRootComponent")); //We attach the components to this root 
	}

	//Setup default HUD
	
	static ConstructorHelpers::FClassFinder<AHUD> HUDClassObject(TEXT("/Script/QBert_Project.MainMenuHUD"));
	HUDClass = HUDClassObject.Class;

	static ConstructorHelpers::FClassFinder<APawn> DummyPawn(TEXT("/Script/QBert_Project.DummyInputPawn"));
	DefaultPawnClass = DummyPawn.Class;

	//Main Menu music Setup
	MenuMusicComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("MenuMusicComponent"));
	MenuMusicComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundCue> jumpSoundAsset(TEXT("/Game/QBertFolders/Sounds/Game_Start_Music_Cue.Game_Start_Music_Cue"));
	MenuMusic = jumpSoundAsset.Object;
	MenuMusicComponent->SetSound(MenuMusic);


}


// Called every frame
void AMainGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayBackgroundMusicClock += DeltaTime;

	if (PlayBackgroundMusicClock >= 4.5f)
	{
		MenuMusicComponent->Play();
		PlayBackgroundMusicClock = 0.0f;
	}
}