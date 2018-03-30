// Fill out your copyright notice in the Description page of Project Settings.

#include "UIElements.h"


// Sets default values
AUIElements::AUIElements()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		//If there is no root component then we create one, we do this check as an object may have a root
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerUITextRoot")); //We attach the components to this root 
	}

	//Set Component for Player Text UI and Animation
	PlayerTextUIComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PlayerUITextComponent"));
	PlayerTextUIComponent->SetupAttachment(RootComponent);
	//ConstructorHelpers can only be use in the constructor
	ConstructorHelpers::FObjectFinder<UPaperFlipbook> PlayerTextUIAsset(TEXT("/Game/QBertFolders/Sprites/PlayerUIText/Player1UIFlipAnimation.Player1UIFlipAnimation"));

	PlayerTextUIAnimation = PlayerTextUIAsset.Object;
	PlayerTextUIComponent->SetFlipbook(PlayerTextUIAnimation);

	//***********************************
	//Set Component for Arrows UI and Animation

	ArrowsUIHolder = CreateDefaultSubobject<USceneComponent>(TEXT("ArrowsUIRoot"));
	ArrowsUIHolder->SetupAttachment(RootComponent);

	ArrowsUIComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("ArrowsUIComponent"));
	ArrowsUIComponent->SetupAttachment(ArrowsUIHolder);
	//ConstructorHelpers can only be use in the constructor
	ConstructorHelpers::FObjectFinder<UPaperFlipbook> ArrowsUIAsset(TEXT("/Game/QBertFolders/Sprites/UI/ArrowUIAnimation.ArrowUIAnimation"));

	ArrowsUIAnimation = ArrowsUIAsset.Object;
	ArrowsUIComponent->SetFlipbook(ArrowsUIAnimation);

	ArrowsUIHolder->RelativeLocation = FVector(-1.0f, 0.0f, -44.0f);

	//////****************************
	//Set Component for Level Text UI
	LevelTextHolder = CreateDefaultSubobject<USceneComponent>(TEXT("LevelUITextRoot"));
	LevelTextHolder->SetupAttachment(RootComponent);

	LevelUIText = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("LevelUITextComponent"));

	LevelUIText->SetupAttachment(LevelTextHolder);
	//ConstructorHelpers can only be use in the constructor
	static ConstructorHelpers::FObjectFinder<UPaperSprite> LevelUITextSprite(TEXT("/Game/QBertFolders/Sprites/PlayerUIText/LevelUIText.LevelUIText"));

	LevelUIText->SetSprite(LevelUITextSprite.Object);
	
	//Set Relative location to parent, technically an offset from parent location.
	LevelTextHolder->RelativeLocation = FVector(176.0f, 0.0f, -32.0f);

	//////****************************
	//Set Component for Round Text UI
	RoundTextHolder = CreateDefaultSubobject<USceneComponent>(TEXT("RoundUITextRoot"));
	RoundTextHolder->SetupAttachment(RootComponent);

	RoundUIText = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("RoundUITextComponent"));

	RoundUIText->SetupAttachment(RoundTextHolder);
	//ConstructorHelpers can only be use in the constructor
	static ConstructorHelpers::FObjectFinder<UPaperSprite> RoundUITextSprite(TEXT("/Game/QBertFolders/Sprites/PlayerUIText/RoundUIText.RoundUIText"));

	RoundUIText->SetSprite(RoundUITextSprite.Object);

	//Set Relative location to parent, technically an offset from parent location.
	RoundTextHolder->RelativeLocation = FVector(176.0f, 0.0f, -40.0f);

	//////****************************
	//Set Component for ChangeToText Text UI
	ChangeToTextHolder = CreateDefaultSubobject<USceneComponent>(TEXT("ChangeToUITextRoot"));
	ChangeToTextHolder->SetupAttachment(RootComponent);

	ChangeToUIText = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ChangeToUITextComponent"));

	ChangeToUIText->SetupAttachment(ChangeToTextHolder);
	//ConstructorHelpers can only be use in the constructor
	static ConstructorHelpers::FObjectFinder<UPaperSprite> ChangeToUITextSprite(TEXT("/Game/QBertFolders/Sprites/PlayerUIText/ChangeToUIText.ChangeToUIText"));

	ChangeToUIText->SetSprite(ChangeToUITextSprite.Object);

	//Set Relative location to parent, technically an offset from parent location.
	ChangeToTextHolder->RelativeLocation = FVector(0.0f, 0.0f, -31.0f);


	//////****************************
	//Set Component for ChangeToCube UI

	ChangeToCubeHolder = CreateDefaultSubobject<USceneComponent>(TEXT("ChangeToCubeUIRoot"));
	ChangeToCubeHolder->SetupAttachment(RootComponent);

	ChangeToCubeUI = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ChangeToCubeUIComponent"));

	ChangeToCubeUI->SetupAttachment(ChangeToCubeHolder);
	//ConstructorHelpers can only be use in the constructor
	static ConstructorHelpers::FObjectFinder<UPaperSprite> ChangeToCubeUISprite(TEXT("/Game/QBertFolders/Sprites/ChangeToCubes/GreenToPurple.GreenToPurple"));

	ChangeToCubeUI->SetSprite(ChangeToCubeUISprite.Object);

	//Set Relative location to parent, technically an offset from parent location.
	ChangeToCubeHolder->RelativeLocation = FVector(-1.0f, 0.0f, -44.0f);

	//////****************************
	//Set Component for Player Number UI

	PlayerNumberHolder = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerNumberUIRoot"));
	PlayerNumberHolder->SetupAttachment(RootComponent);

	PlayerNumberUI = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PlayerNumberUIComponent"));

	PlayerNumberUI->SetupAttachment(PlayerNumberHolder);
	//ConstructorHelpers can only be use in the constructor
	static ConstructorHelpers::FObjectFinder<UPaperSprite> PlayerNumberUISprite(TEXT("/Game/QBertFolders/Sprites/UI/PlayerNumberONE.PlayerNumberONE"));

	PlayerNumberUI->SetSprite(PlayerNumberUISprite.Object);

	//Set Relative location to parent, technically an offset from parent location.
	PlayerNumberHolder->RelativeLocation = FVector(35.0f, 0.0f, 0.0f);

	//Find Font and Material for the font

	static ConstructorHelpers::FObjectFinder<UFont> QbertFontAsset(TEXT("/Game/QBertFolders/Font/QbertRevised_Font.QbertRevised_Font"));
	static ConstructorHelpers::FObjectFinder<UMaterial> QbertFontMaterial(TEXT("/Game/QBertFolders/Font/MyTextMaterial.MyTextMaterial"));

	QbertFont = QbertFontAsset.Object;
	FontMaterial = QbertFontMaterial.Object;

	//////****************************
	//Set Text Render Component for Score
	score = 0;
	//Convert Int into string - string to text
	ScoreString = FText::FromString(FString::FromInt(score));

	ScoreUIHolder = CreateDefaultSubobject<USceneComponent>(TEXT("ScoreTextUIRoot"));
	ScoreUIHolder->SetupAttachment(RootComponent);

	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreTextComponent"));
	ScoreText->SetupAttachment(ScoreUIHolder);
	ScoreText->SetFont(QbertFont); 
	ScoreText->SetTextMaterial(FontMaterial);
	ScoreText->SetText(ScoreString);
	ScoreText->SetTextRenderColor(FColor::FColor(255,31,0,255));
	ScoreText->HorizontalAlignment = EHorizTextAligment::EHTA_Left; // Sets Text aligment to the center
	ScoreText->WorldSize = 9;
	
	ScoreText->AddRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	ScoreUIHolder->RelativeLocation = FVector(-25.0f, 2.0f, -16.0f);

	//////*****************************
	//Set Text Render for pause options
	PauseOptionsHolder = CreateDefaultSubobject<USceneComponent>(TEXT("PauseOptionsHolderRoot"));
	PauseOptionsHolder->SetupAttachment(RootComponent);

	PauseOptionsText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("PauseOptionsTextComponent"));
	PauseOptionsText->SetupAttachment(PauseOptionsHolder);
	PauseOptionsText->SetFont(QbertFont);
	PauseOptionsText->SetTextMaterial(FontMaterial);
	PauseOptionsText->SetText(TEXT("Press U to Unpause \nPress Q for Main Menu"));
	PauseOptionsText->SetTextRenderColor(FColor::FColor(255, 31, 0, 255));
	PauseOptionsText->HorizontalAlignment = EHorizTextAligment::EHTA_Center; // Sets Text aligment to the center
	PauseOptionsText->WorldSize = 9;

	PauseOptionsText->AddRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));

	PauseOptionsHolder->RelativeLocation = FVector(180.0f, 3.0f, 0.0f);

	//////****************************
	//Set Text Render Component for Level number
	LevelNumber = 1;
	//Convert Int into string - string to text
	LevelNumberString = FText::FromString(FString::FromInt(LevelNumber));

	LevelNumberHolder = CreateDefaultSubobject<USceneComponent>(TEXT("LevelNumberHolderRoot"));
	LevelNumberHolder->SetupAttachment(RootComponent);

	LevelNumberText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("LevelNumberTextComponent"));
	LevelNumberText->SetupAttachment(LevelNumberHolder);
	LevelNumberText->SetFont(QbertFont);
	LevelNumberText->SetTextMaterial(FontMaterial);
	LevelNumberText->SetText(LevelNumberString);
	LevelNumberText->SetTextRenderColor(FColor::FColor(255, 31, 0, 255));
	LevelNumberText->HorizontalAlignment = EHorizTextAligment::EHTA_Left; // Sets Text aligment to the center
	LevelNumberText->WorldSize = 9;

	LevelNumberText->AddRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	LevelNumberHolder->RelativeLocation = FVector(187.0f, 0.0f, -36.0f);

	//////****************************
	//Set Text Render Component for Round number
	RoundNumber = 1;
	//Convert Int into string - string to text
	RoundNumberString = FText::FromString(FString::FromInt(RoundNumber));

	RoundNumberHolder = CreateDefaultSubobject<USceneComponent>(TEXT("RoundNumberHolderRoot"));
	RoundNumberHolder->SetupAttachment(RootComponent);

	RoundNumberText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("RoundNumberTextComponent"));
	RoundNumberText->SetupAttachment(RoundNumberHolder);
	RoundNumberText->SetFont(QbertFont);
	RoundNumberText->SetTextMaterial(FontMaterial);
	RoundNumberText->SetText(RoundNumberString);
	RoundNumberText->SetTextRenderColor(FColor::FColor(255, 31, 0, 255));
	RoundNumberText->HorizontalAlignment = EHorizTextAligment::EHTA_Left; // Sets Text aligment to the center
	RoundNumberText->WorldSize = 9;

	RoundNumberText->AddRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	RoundNumberHolder->RelativeLocation = FVector(187.0f, 0.0f, -45.0f);
	
	//////****************************
	//Set Component for Lives UI

	//Get Lives Sprite
	static ConstructorHelpers::FObjectFinder<UPaperSprite> LivesUISprite(TEXT("/Game/QBertFolders/Sprites/UI/QberLivesUI.QberLivesUI"));
	LivesSprite = LivesUISprite.Object;
	LivesUIHolder = CreateDefaultSubobject<USceneComponent>(TEXT("LivesUIHolderUIRoot"));
	LivesUIHolder->SetupAttachment(RootComponent);
	//Set Relative location to parent, technically an offset from parent location.
	LivesUIHolder->RelativeLocation = FVector(-30.0f, 0.0f, -62.0f);
	

	for (int i = 0; i < 9; i++)
	{
		//Create Strings for name children
		FString newRootName = "LivesUIHolderUIChild" + FString::FromInt(i);
		FString newSpriteComponentName = "LivesUIComponent" + FString::FromInt(i);

		//Create Child holder
		USceneComponent* LivesUIHolderChild = CreateDefaultSubobject<USceneComponent>(FName(*newRootName));
		LivesUIHolderChild->SetupAttachment(LivesUIHolder);

		//Create Sprite component
		UPaperSpriteComponent* LivesUISpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(FName(*newSpriteComponentName));
		LivesUISpriteComponent->SetupAttachment(LivesUIHolderChild);
		LivesUISpriteComponent->SetSprite(LivesSprite);

		//Add Live Holder to the array
		LivesSpriteArray[i] = LivesUIHolderChild;

		//Set Relative location to parent, technically an offset from parent location.
		if (i < 5)
		{
			LivesSpriteArray[i]->RelativeLocation = FVector(0.0f, 0.0f, -16.0f * i);
		}
		else if (i >= 5)
		{
			LivesSpriteArray[i]->RelativeLocation = FVector(15.0f, 0.0f, -16.0f * indexSecondRowLives);
			indexSecondRowLives++;
		}
		
		LivesSpriteArray[i]->RelativeRotation = SpriteVisible;
	}
	
}

// Called when the game starts or when spawned
void AUIElements::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUIElements::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUIElements::showPausedOptions(bool isPaused)
{
	if (isPaused)
	{
		PauseOptionsText->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	}
	else
	{
		PauseOptionsText->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	}	
}
