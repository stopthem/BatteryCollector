// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryCollector/Public/Spawners/BatterySpawnerBase.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
ABatterySpawnerBase::ABatterySpawnerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawner"));
}

// Called when the game starts or when spawned
void ABatterySpawnerBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABatterySpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector ABatterySpawnerBase::GetRandomSpawnPoint() const
{
	const FVector SpawnOrigin = SpawnVolume->Bounds.Origin;
	const FVector SpawnLimit = SpawnVolume->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnLimit);
}
