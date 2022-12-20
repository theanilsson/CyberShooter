// Fill out your copyright notice in the Description page of Project Settings.


#include "CyberShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ACyberShooterPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    if(bIsWinner)
    {
        UUserWidget* WinScreenWidget = CreateWidget(this, WinScreenClass);
        if(WinScreenWidget)
        {
            WinScreenWidget->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LoseScreenWidget = CreateWidget(this, LoseScreenClass);
        if(LoseScreenWidget)
        {
            LoseScreenWidget->AddToViewport();
        }
    }

    GetWorldTimerManager().SetTimer(RestartHandle, this, &APlayerController::RestartLevel, RestartDelay);
}
