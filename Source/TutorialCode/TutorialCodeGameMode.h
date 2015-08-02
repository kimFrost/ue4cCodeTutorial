// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "SpawnVolume.h"
#include "TutorialCodeGameMode.generated.h"

// Enum to store the current state of gameplay
enum class ETutorialCodePlayState : uint8 //** you can replace short with uint8 */
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class ATutorialCodeGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATutorialCodeGameMode(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float DecayRate;

	ETutorialCodePlayState GetCurrentState() const;

	void SetCurrentState(ETutorialCodePlayState NewState);

	virtual void BeginPlay() override;

	 
private:

	TArray<ASpawnVolume*> SpawnVolumeActors;

	// Store the current playstate
	ETutorialCodePlayState CurrentState;

	void HandleNewState(ETutorialCodePlayState NewState);

};



FORCEINLINE ETutorialCodePlayState ATutorialCodeGameMode::GetCurrentState() const
{
	return CurrentState;
}