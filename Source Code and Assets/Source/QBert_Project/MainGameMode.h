// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "MainMenuHUD.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class QBERT_PROJECT_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
		AMainGameMode();
		// Called every frame
		virtual void Tick(float DeltaTime) override;
		
private:
	//Enemy spawn Clock
	float PlayBackgroundMusicClock;
	//Main Menu Music
	UAudioComponent* MenuMusicComponent;
	USoundCue*       MenuMusic;
	
};
