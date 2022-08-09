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

	//Log Notes
	//FString MyString = "My String Value";

	//FString Name = GetName();


	//Log(What type of log category, Level of the log the urgency, the text of the message printing) found in the output log
	//UE_LOG(LogTemp, Display, TEXT("TEXT Message"));

	// UE_LOG(LogTemp, Display, TEXT("TEXT Message: %s"), *MyString);

	//UE_LOG(LogTemp, Display, TEXT("TEXT Message: %s"), *Name);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);

	



}


void AMovingPlatform::MovePlatform(float DeltaTime){

	if (ShouldPlatformReturn()){
		

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}else{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;

		SetActorLocation(CurrentLocation);
	}

}

void AMovingPlatform:: RotatePlatform(float DeltaTime){

	AddActorLocalRotation(RotationVelocity * DeltaTime);
	
}

bool AMovingPlatform::ShouldPlatformReturn() const
{

	return GetDistanceMoved() >= MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{

	return FVector::Dist(StartLocation, GetActorLocation());

}