// Fill out your copyright notice in the Description page of Project Settings.


#include "CyberShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ACyberShooterPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    UUserWidget* LoseScreenWidget = CreateWidget(this, LoseScreenClass);
    if(LoseScreenWidget != nullptr)
    {
        LoseScreenWidget->AddToViewport();
    }

    GetWorldTimerManager().SetTimer(RestartHandle, this, &APlayerController::RestartLevel, RestartDelay);
}
