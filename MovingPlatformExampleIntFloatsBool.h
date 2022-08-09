// Fill out your copyright notice in the Description page of Project Settings.
//Just some examples for future to be pushed to github

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

	UPROPERTY(EditAnywhere)
	int32 MyInt = 46;

	UPROPERTY(EditAnywhere)
	int32 InputA = 12;

	UPROPERTY(EditAnywhere)
	int32 InputB = 7;

	UPROPERTY(EditAnywhere)
	int32 APlusB = 0;

	UPROPERTY(EditAnywhere)
	bool MyBool = true;

	UPROPERTY(EditAnywhere)
	float MyFloat = 30;

};
