// Fill out your copyright notice in the Description page of Project Settings.

#include "TutorialCode.h"
#include "TutorialCodeHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "TutorialCodeGameMode.h"
#include "TutorialCodeCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ATutorialCodeHUD::ATutorialCodeHUD(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
	// Use the RobotoDistanceField form the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}

void ATutorialCodeHUD::DrawHUD()
{
	// Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	// Call to the parent versions of DrawHUD
	//Change Super::DrawHUD to the below;
	Super::DrawHUD();
	//&AHUD::DrawHUD;

	// Get the character and print its power level
	ATutorialCodeCharacter* MyCharacter = Cast<ATutorialCodeCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (MyCharacter)
	{
		FString PowerLevelString = FString::Printf(TEXT("%10.1f"), FMath::Abs(MyCharacter->PowerLevel));
		//PowerLevelString = TEXT("TEST FIND ME!!!!!");
		DrawText(PowerLevelString, FColor::White, 50, 50, HUDFont);
	}

	ATutorialCodeGameMode* MyGameMode = Cast<ATutorialCodeGameMode>(UGameplayStatics::GetGameMode(this));
	// IF the game is over
	if (MyGameMode->GetCurrentState() == ETutorialCodePlayState::EGameOver)
	{
		// Create a variable for storing the size of printing Game over
		FVector2D GameOverSize;
		GetTextSize(TEXT("GAME OVER"), GameOverSize.X, GameOverSize.Y, HUDFont);
		DrawText(TEXT("GAME OVER"), FColor::White, (ScreenDimensions.X - GameOverSize.X) / 2.0f, (ScreenDimensions.Y - GameOverSize.Y) / 2.0f, HUDFont);

	}

}