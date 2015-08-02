// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class TUTORIALCODE_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume(const FObjectInitializer &ObjectInitializer);

	/** BoxComponent to specify the spawning area within the level */
	UPROPERTY(VisibleInstanceOnly, Category = "Spawning")
	class UBoxComponent* WhereToSpawn;

	/** The pickup to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
	//class APickup* WhatToSpawn;
	TSubclassOf<class APickup> WhatToSpawn;

	/** Minimum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	/** Maximum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

	/** Find a random point with the BoxComponent */
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();


	void EnableSpawning();

	void DisableSpawning();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


private:

	/** Whether or not spawning is enabled */
	bool bSpawningEnabled;

	/** Calculates a random spawn delay */
	float GetRandomSpawnDelay();

	/** The current spawn delay */
	float SpawnDelay;

	/** Handles the spawning of a new pickup */
	void SpawnPickup();

	/** The timer for when to spawn the pickup */
	float SpawnTime;

};
