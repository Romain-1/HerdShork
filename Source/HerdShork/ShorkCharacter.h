// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "ShorkCharacter.generated.h"

UCLASS()
class HERDSHORK_API AShorkCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShorkCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	USkeletalMeshComponent* _mesh;

	UPROPERTY(Transient)
		UCameraComponent* _camera;

	UPROPERTY(Transient)
		USpringArmComponent* _arm;

	bool isSwimming = false;
	bool isSprinting = false;

	float _currentSpeed = 0;

public:
	UPROPERTY(BlueprintReadWrite)
		float Speed = 1000;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void MouseMoved(FVector direction);

	UFUNCTION(BlueprintCallable)
		void StartSwim();

	UFUNCTION(BlueprintCallable)
		void StopSwim();

	UFUNCTION(BlueprintCallable)
		void StartSprint();

	UFUNCTION(BlueprintCallable)
		void StopSprint();
};
