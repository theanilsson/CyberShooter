// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class CYBERSHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsAlive() const;

private:
	// UPROPERTY(EditAnywhere)
	// float AcceptanceRadius = 200.0f;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
// private:
// 	void SetFocus() override;
// 	void SetFocalPoint() override;
// 	void ClearFocus(EAIFocusPriority::Type InPriority) override;
};
