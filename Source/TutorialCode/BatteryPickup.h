// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

UCLASS()
class TUTORIALCODE_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABatteryPickup(const FObjectInitializer &ObjectInitializer);

	/** Set the amount of power the battery gives to the player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power")
	float PowerLevel;

	/** Override the OnPickedUp function (Use _Implementation because this is a BlueprintNativeEvent) */
	void OnPickedUp_Implementation() override;

};
