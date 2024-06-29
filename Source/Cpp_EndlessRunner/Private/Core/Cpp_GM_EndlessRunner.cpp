// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Cpp_GM_EndlessRunner.h"
#include "Actors/Cpp_Floor.h"
#include "Components/ArrowComponent.h"
#include "Widgets/Cpp_WGT_HUD.h"


void ACpp_GM_EndlessRunner::CreateInitialFloorTiles() {
	// 3 Initial Floor Tiles Without Obstacles
	ACpp_Floor* Tile = AddFloorTile(false);
	if (Tile) {
		LaneOffsets.Add(Tile->LeftLane->GetComponentLocation().Y);
		LaneOffsets.Add(Tile->CenterLane->GetComponentLocation().Y);
		LaneOffsets.Add(Tile->RightLane->GetComponentLocation().Y);
	}	
	// Remaining 2 Tiles
	AddFloorTile(false);
	AddFloorTile(false);

	// Remaining Tiles With Obstacles
	for (int i = 0; i < InitialFloorTiles-3; i++) {
		AddFloorTile(true);

	}
}

ACpp_Floor* ACpp_GM_EndlessRunner::AddFloorTile(const bool bSpawnItems) {
	UWorld* World = GetWorld();
	if (World) {
		// Spawn Tile with custom constructor
		ACpp_Floor* Tile = World->SpawnActor<ACpp_Floor>(FloorTileClass, NextSpawnPoint);
		Tile->SetGameModeRef(this);
		if (Tile) {
			if (bSpawnItems) {
				Tile->SpawnItems();
			}
			NextSpawnPoint = Tile->GetNextSpawnPoint();

		}
		return Tile;
	}
	return nullptr;
}

float ACpp_GM_EndlessRunner::GetLaneOffset(int32 index) const {
	return LaneOffsets[index];
}

void ACpp_GM_EndlessRunner::CoinCollected() {
	CoinsCollected++;
	// Update HUD
	if (WGT_Hud) {
		WGT_Hud->UpdateCoinsCollected(CoinsCollected);
	}
}

void ACpp_GM_EndlessRunner::BeginPlay() {
	Super::BeginPlay();

	CreateInitialFloorTiles();

	// Create HUD
	if (WGT_HudClass) {
		WGT_Hud = CreateWidget<UCpp_WGT_HUD>(GetWorld(), WGT_HudClass);
		if (WGT_Hud) {
			WGT_Hud->AddToViewport();
		}
	}
}
