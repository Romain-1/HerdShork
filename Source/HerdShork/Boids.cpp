// Fill out your copyright notice in the Description page of Project Settings.


#include "Boids.h"

// Sets default values
ABoids::ABoids()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoids::BeginPlay()
{
	Super::BeginPlay();
	
	for (unsigned i = 0; i < FishCount; ++i)
	{
		AActor* f = GetWorld()->SpawnActor(fish);
		f->SetActorLocation(FVector(
			FMath::FRandRange(-SpawnCubeRange, SpawnCubeRange),
			FMath::FRandRange(0.f, SpawnCubeRange * 2.f),
			FMath::FRandRange(-SpawnCubeRange, SpawnCubeRange)
		));
		m_fishes.push_back(f);
	}
}

// Called every frame
void ABoids::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (auto f : m_fishes)
	{

	}
}

