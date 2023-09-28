// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boids.generated.h"

UCLASS()
class HERDSHORK_API ABoids : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoids();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Fish")
		TSubclassOf<AActor> fish;

	float SpawnCubeRange = 5000;
	unsigned FishCount = 100;

private:
	std::vector<AActor*> m_fishes;
};
