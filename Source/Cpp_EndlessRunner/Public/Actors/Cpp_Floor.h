// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_Floor.generated.h"

// Forward Declarations
class USceneComponent;
class UStaticMeshComponent;
class UArrowComponent;
class UBoxComponent;
class ACpp_GM_EndlessRunner;
class ACpp_Obstacle;

UCLASS()
class CPP_ENDLESSRUNNER_API ACpp_Floor : public AActor
{
	GENERATED_BODY()
	
public:		
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================	
	// Lanes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* CenterLane;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* LeftLane;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* RightLane;
	

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	ACpp_Floor();	

	virtual void BeginPlay() override;

	FORCEINLINE const FTransform GetNextSpawnPoint() const;

	void SetGameModeRef(ACpp_GM_EndlessRunner* inGamemode);

	// Spawn Items
	UFUNCTION()
	void SpawnItems();
	UFUNCTION()
	void SpawnLaneItem(UArrowComponent* Lane);

protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* FloorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* AttachPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floor")
	UBoxComponent* FloorTrigger;

	UPROPERTY(VisibleInstanceOnly)
	ACpp_GM_EndlessRunner* GameModeRef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	TSubclassOf<ACpp_Obstacle> SmallObstacleClass;

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================	

	// BeginOverlap Function
	UFUNCTION()
	void OnFloorTriggerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
