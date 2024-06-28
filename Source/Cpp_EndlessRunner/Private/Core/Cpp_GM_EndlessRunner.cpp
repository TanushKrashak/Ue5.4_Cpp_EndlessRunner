// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Cpp_GM_EndlessRunner.h"
#include "Actors/Cpp_Floor.h"


void ACpp_GM_EndlessRunner::CreateInitialFloorTiles() {
	for (int i = 0; i < InitialFloorTiles; i++) {
		AddFloorTile();
	}
}

void ACpp_GM_EndlessRunner::AddFloorTile() {
	UWorld* World = GetWorld();
	if (World) {
		// Spawn Tile with custom constructor
		ACpp_Floor* Tile = World->SpawnActor<ACpp_Floor>(FloorTileClass, NextSpawnPoint);
		Tile->SetGameModeRef(this);
		if (Tile) {
			NextSpawnPoint = Tile->GetNextSpawnPoint();

		}
	}

}

void ACpp_GM_EndlessRunner::BeginPlay() {
	Super::BeginPlay();

	CreateInitialFloorTiles();
}
