// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShooterCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void AShooterCharacter::MoveSideways(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

void AShooterCharacter::LookUpRate(float Value)
{
	AddControllerPitchInput(Value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this));
}

void AShooterCharacter::LookSidewaysRate(float Value)
{
	AddControllerYawInput(Value * RotationRate * UGameplayStatics::GetWorldDeltaSeconds(this));
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookSideways", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AShooterCharacter::LookUpRate);
	PlayerInputComponent->BindAxis("LookSidewaysRate", this, &AShooterCharacter::LookSidewaysRate);
	PlayerInputComponent->BindAxis("MoveForward", this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveSideways", this, &AShooterCharacter::MoveSideways);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

