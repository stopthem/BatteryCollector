// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Pickups/PickupBase.h"
#include "BatterySpawnerBase.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ABatterySpawnerBase : public AActor
{
	GENERATED_BODY()

	void SpawnBatteryActor();

public:
	// Sets default values for this actor's properties
	ABatterySpawnerBase();

protected:
	void SetTimer();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawner")
	UBoxComponent* SpawnVolume;

	UPROPERTY(EditAnywhere, Category="Spawner")
	TSubclassOf<APickupBase> ActorToSpawn;

	UPROPERTY(EditAnywhere, Category="Spawner")
	FFloatRange RandomSpawnRotationYawRange;

	TTuple<FVector, FRotator> GetRandomPointRotation() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	FVector2D SpawnDelayRange;
	float SpawnDelay;
	FTimerHandle SpawnTimerHandle;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
