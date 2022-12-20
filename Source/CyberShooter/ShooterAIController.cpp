// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

    if(AIBehavior)
    {
        RunBehaviorTree(AIBehavior);

        GetBlackboardComponent()->SetValueAsVector("PlayerLocation", PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector("StartLocation", GetPawn()->GetActorLocation());
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AShooterAIController::IsAlive() const
{
    AShooterCharacter* OwnerCharacter = Cast<AShooterCharacter>(GetPawn());
    if(OwnerCharacter)
    {
        return OwnerCharacter->IsAlive();
    }
    return true;
}
