// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryCollector/Public/Pickups/PickupBase.h"

// Sets default values
APickupBase::APickupBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = PickupMesh;
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


bool APickupBase::IsPickupActive() const
{
	return bIsActive;
}

void APickupBase::SetIsActive(bool bStatus)
{
	bIsActive = bStatus;
}

void APickupBase::OnPickupCollected_Implementation()
{
	SetIsActive(false);

	const FString DebugString = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Picked up :  %s"), *DebugString);
}
