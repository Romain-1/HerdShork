// Fill out your copyright notice in the Description page of Project Settings.


#include "ShorkCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"


// Sets default values
AShorkCharacter::AShorkCharacter()
{
	//Super::ACharacter();

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//RootComponent = arm;
	_arm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	_arm->TargetArmLength = 500.f;

	_mesh = GetMesh();

	UE_LOG(LogTemp, Log, TEXT("ALEEEEEEEED2 %p"), _mesh);

	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_camera->AttachToComponent(_arm, FAttachmentTransformRules::KeepRelativeTransform);
	// GetComponent
	// GetComponentByClass(arm);
	// GetComponentByClass(USpringArmComponent::StaticClass())
	// arm = Cast<USpringArmComponent>();
}

// Called when the game starts or when spawned
void AShorkCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShorkCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector pos = GetActorLocation();
	pos += _mesh->GetForwardVector() * DeltaTime * _currentSpeed;
	SetActorLocation(pos);

	if (isSwimming)
	{
		_currentSpeed = FMath::Lerp(_currentSpeed, Speed * (isSprinting ? 2 : 1), 0.2);
		UE_LOG(LogTemp, Log, TEXT("%f %f"), _currentSpeed, Speed);

		FRotator rot = _mesh->GetComponentRotation();

		_mesh->SetWorldRotation(
			FQuat::Slerp(
				rot.Quaternion(),
				_camera->GetComponentRotation().Quaternion(),
				0.1
			).Rotator()
		);
		if (isSprinting)
			_arm->TargetArmLength = FMath::Lerp(_arm->TargetArmLength, 1000.f, 0.2);
		else
			_arm->TargetArmLength = FMath::Lerp(_arm->TargetArmLength, 500.f, 0.2);
	}
	else
	{
		_currentSpeed = FMath::Lerp(_currentSpeed, 0, 0.01);
		_arm->TargetArmLength = FMath::Lerp(_arm->TargetArmLength, 500.f, 0.2);
	}
}

// Called to bind functionality to input
void AShorkCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AShorkCharacter::MouseMoved(FVector direction)
{
	FRotator rotator = _arm->GetComponentRotation();
	rotator.Yaw += direction.X;
	rotator.Pitch += direction.Y;
	_arm->SetWorldRotation(rotator);
}

void AShorkCharacter::StartSwim() { isSwimming = true; }
void AShorkCharacter::StopSwim() { isSwimming = false; }
void AShorkCharacter::StartSprint() { isSprinting = true; }
void AShorkCharacter::StopSprint() { isSprinting = false; }
