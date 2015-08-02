// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TutorialCode.h"
#include "TutorialCodeGameMode.h"
#include "TutorialCodeCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "TutorialCodeHUD.h"


ATutorialCodeGameMode::ATutorialCodeGameMode(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// Set the default HUD class
	HUDClass = ATutorialCodeHUD::StaticClass();

	// Base decay rate
	DecayRate = 0.25f;


}

void ATutorialCodeGameMode::Tick(float DeltaTime)
{
	ATutorialCodeCharacter* MyCharacter = Cast<ATutorialCodeCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	// If the character still have power
	if (MyCharacter->PowerLevel > 0.05)
	{
		// Decrease the character's power
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.f, DeltaTime, DecayRate);
	}
	else 
	{
		SetCurrentState(ETutorialCodePlayState::EGameOver);
	}
}

void ATutorialCodeGameMode::SetCurrentState(ETutorialCodePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(NewState);
}

void ATutorialCodeGameMode::HandleNewState(ETutorialCodePlayState NewState)
{
	switch (NewState)
	{
		// When we are playing, the spawn volumes can spawn
		case ETutorialCodePlayState::EPlaying:
		{
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->EnableSpawning();
			}
		}
		break;

		// If the game is over, the spawn volumes should deactivates
		case ETutorialCodePlayState::EGameOver:
		{
			for (ASpawnVolume* Volume : SpawnVolumeActors)
			{
				Volume->DisableSpawning();
			}
			// Get player controller at index 0
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
			PlayerController->SetCinematicMode(true, true, true);
		}
		break;

		case ETutorialCodePlayState::EUnknown:
			// Do nothing
			break;
	}
}

void ATutorialCodeGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Find all spawn volume actors
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor)
		{
			SpawnVolumeActors.Add(SpawnVolumeActor);
		}
	}


	SetCurrentState(ETutorialCodePlayState::EPlaying);
}