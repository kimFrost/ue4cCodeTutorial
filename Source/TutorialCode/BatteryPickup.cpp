// Fill out your copyright notice in the Description page of Project Settings.

#include "TutorialCode.h"
#include "BatteryPickup.h"


// Sets default values
ABatteryPickup::ABatteryPickup(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
	// The base power level of the battery
	PowerLevel = 150.f;
}

void ABatteryPickup::OnPickedUp_Implementation()
{
	// Cal the parent implementation of the OnPickedUp first.
	Super::OnPickedUp_Implementation();
	// Destroy the battery
	Destroy();
}