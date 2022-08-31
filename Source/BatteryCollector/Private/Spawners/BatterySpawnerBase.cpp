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

void ABatterySpawnerBase::SetTimer()
{
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABatterySpawnerBase::SpawnBatteryActor, SpawnDelay);
}

// Called when the game starts or when spawned
void ABatterySpawnerBase::BeginPlay()
{
	Super::BeginPlay();

	SpawnDelay = FMath::RandRange(SpawnDelayRange.X, SpawnDelayRange.Y);

	SetTimer();
}

// Called every frame
void ABatterySpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TTuple<FVector, FRotator> ABatterySpawnerBase::GetRandomPointRotation() const
{
	const FVector SpawnOrigin = SpawnVolume->Bounds.Origin;
	const FVector SpawnLimit = SpawnVolume->Bounds.BoxExtent;

	return MakeTuple(UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnLimit), UKismetMathLibrary::RandomRotator());
}

void ABatterySpawnerBase::SpawnBatteryActor()
{
	if (!ActorToSpawn)return;

	FActorSpawnParameters Parameters;
	Parameters.Owner = this;
	Parameters.Instigator = GetInstigator();
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	if (!GetWorld())return;

	const auto RandomPointRotation = GetRandomPointRotation();

	auto* SpawnedActor = GetWorld()->SpawnActor<APickupBase>(ActorToSpawn, RandomPointRotation.Key, RandomPointRotation.Value, Parameters);

	SetTimer();
}
