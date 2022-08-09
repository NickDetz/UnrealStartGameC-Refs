// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	//getting the actor location at the start
	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	// CurrentLocation.X = CurrentLocation.X +1;

	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;

	SetActorLocation(CurrentLocation);
	//Scope Resolution Operator :: looks inside a class
	//Allows to look inside a class like the dot operator but not for instance that is the dot operator
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	//Reversing the direction if they go to far
	if (DistanceMoved >= MoveDistance){
		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}



}

