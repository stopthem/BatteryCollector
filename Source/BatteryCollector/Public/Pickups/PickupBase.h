// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickupBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickupBase();

	UFUNCTION(BlueprintPure, Category="Pickup")
	bool IsPickupActive() const;

	UFUNCTION(BlueprintCallable, Category="Pickup")
	void SetIsActive(bool bStatus);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsActive = true ;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* PickupMesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintNativeEvent)
	void OnPickupCollected();
};
