// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root Component");
	SetRootComponent(Root);
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Gun Mesh");
	GunMesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleEmitter, GunMesh, "MuzzleFlashSocket");

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if(!OwnerPawn) return;
	AController* OwnerController = OwnerPawn->GetController();
	if(!OwnerController) return;

	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

	//"ECC_GameTraceChannel1"
	FVector EndLocation = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;

	// DrawDebugPoint(GetWorld(), EndLocation, 25.0f, FColor::Orange, true);
	// DrawDebugPoint(GetWorld(), ViewPointLocation, 25.0f, FColor::Orange, true);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(OwnerPawn);
	bool HitSomething = GetWorld()->LineTraceSingleByChannel(HitResult, ViewPointLocation, EndLocation, ECollisionChannel::ECC_GameTraceChannel1, Params);
	if(HitSomething)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitEmitter, HitResult.Location, (-ViewPointRotation.Vector()).Rotation());
		FPointDamageEvent DamageEvent (Damage, HitResult, -ViewPointRotation.Vector(), nullptr);
		AActor* HitActor = HitResult.GetActor();
		if(HitActor)
		{
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, OwnerPawn);
		}
	}
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

