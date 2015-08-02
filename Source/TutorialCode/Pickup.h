// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class TUTORIALCODE_API APickup : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APickup(const FObjectInitializer &ObjectInitializer);

	/** True when the pickup is able to be picked up, false if something deactivates the pickup. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	bool bIsActive;

	/** Simple collision primitive to use as the root component. */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
	//TSubobjectPtr<USphereComponent> BaseCollisionComponent;
	class USphereComponent* BaseCollisionComponent;

	/** StaticMeshComponent tp represent the pickup in the level. */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
	//TSubobjectPtr<UStaticMeshComponent> PickupMesh;
	class UStaticMeshComponent* PickupMesh;

	/** Function to call when the Pickup is collected. */
	UFUNCTION(BlueprintNativeEvent)
	void OnPickedUp();


	virtual void OnPickedUp_Implementation();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

};
