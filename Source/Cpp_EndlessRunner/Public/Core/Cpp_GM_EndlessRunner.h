// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Cpp_GM_EndlessRunner.generated.h"

// Forward Declarations
class ACpp_Floor;

UCLASS()
class CPP_ENDLESSRUNNER_API ACpp_GM_EndlessRunner : public AGameModeBase
{
	GENERATED_BODY()

public:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================


	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	UFUNCTION(BlueprintCallable)
	void CreateInitialFloorTiles();

	UFUNCTION(BlueprintCallable)
	void AddFloorTile();


protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	UPROPERTY(EditDefaultsOnly, Category="Config")
	TSubclassOf<ACpp_Floor> FloorTileClass;


	UPROPERTY(EditAnywhere, Category = "Config")
	int32 InitialFloorTiles = 10;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	FTransform NextSpawnPoint;

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	virtual void BeginPlay() override;

};
