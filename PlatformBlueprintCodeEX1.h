// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTICLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//Means I can see and edit anywhere
	UPROPERTY(EditAnywhere, Category="MovingPlatform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category="MovingPlatform")
	float MoveDistance = 500;

	FVector StartLocation;

// Means I can see it anywhere but not able to edit it
	// UPROPERTY(VisibleAnywhere)
	// float DistanceMoved = -1;

};
