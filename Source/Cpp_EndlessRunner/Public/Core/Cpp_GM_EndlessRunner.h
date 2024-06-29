// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Cpp_GM_EndlessRunner.generated.h"

// Forward Declarations
class ACpp_Floor;
class UCpp_WGT_HUD;

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
	ACpp_Floor* AddFloorTile(const bool bSpawnItems);

	UFUNCTION()
	float GetLaneOffset(int32 index) const;

	UFUNCTION()
	void CoinCollected();

protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	// Config
	UPROPERTY(EditDefaultsOnly, Category="Config")
	TSubclassOf<ACpp_Floor> FloorTileClass;
	UPROPERTY(EditAnywhere, Category = "Config")
	int32 InitialFloorTiles = 10;
	UPROPERTY(EditAnywhere, Category = "Config")
	TSubclassOf<UCpp_WGT_HUD> WGT_HudClass;


	// Runtime
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	FTransform NextSpawnPoint;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	TArray<float> LaneOffsets;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	UCpp_WGT_HUD* WGT_Hud;

	UPROPERTY(VisibleAnywhere, Category = "Coins")
	int32 CoinsCollected = 0;


	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	virtual void BeginPlay() override;

};
