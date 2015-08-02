// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "TutorialCodeHUD.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIALCODE_API ATutorialCodeHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// Sets default values for this's properties
	ATutorialCodeHUD(const FObjectInitializer &ObjectInitializer);

	/** Variable for storing the font */
	UPROPERTY()
	UFont* HUDFont;

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	
	
};
