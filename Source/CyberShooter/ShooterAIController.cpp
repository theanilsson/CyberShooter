// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

    SetFocus(PlayerPawn);
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
    MoveToActor(PlayerPawn, 200.0f);
}
