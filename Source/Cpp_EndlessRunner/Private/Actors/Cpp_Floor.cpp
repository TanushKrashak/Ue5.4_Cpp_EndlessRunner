// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Cpp_Floor.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Core/Cpp_GM_EndlessRunner.h"
#include "Actors/Cpp_Obstacle.h"


ACpp_Floor::ACpp_Floor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Setup Scene (root)
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	// Setup Floor Mesh
	FloorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorMesh"));
	FloorMesh->SetupAttachment(Root);

	// Setup Spawn Point
	AttachPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("AttachPoint"));
	AttachPoint->SetupAttachment(Root);

	// Setup Center Lane
	CenterLane = CreateDefaultSubobject<UArrowComponent>(TEXT("CenterLane"));
	CenterLane->SetupAttachment(Root);

	// Setup Left Lane
	LeftLane = CreateDefaultSubobject<UArrowComponent>(TEXT("LeftLane"));
	LeftLane->SetupAttachment(Root);

	// Setup Right Lane
	RightLane = CreateDefaultSubobject<UArrowComponent>(TEXT("RightLane"));
	RightLane->SetupAttachment(Root);

	// Setup Floor Trigger
	FloorTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("FloorTrigger"));
	FloorTrigger->SetupAttachment(Root);
	FloorTrigger->SetBoxExtent(FVector(32.0f, 500.0f, 200.0f));
	FloorTrigger->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
}


void ACpp_Floor::BeginPlay() {
	Super::BeginPlay();
}

FORCEINLINE const FTransform ACpp_Floor::GetNextSpawnPoint() const {
	return AttachPoint->GetComponentTransform(); 
}

void ACpp_Floor::SetGameModeRef(ACpp_GM_EndlessRunner* inGamemode) {
	GameModeRef = inGamemode;
	// Check if the GameModeRef is valid
	check(GameModeRef);

	FloorTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACpp_Floor::OnFloorTriggerOverlap);
		
}

void ACpp_Floor::SpawnItems() {
	if (SmallObstacleClass) {
		SpawnLaneItem(CenterLane);
		SpawnLaneItem(LeftLane);
		SpawnLaneItem(RightLane);
	}
}
void ACpp_Floor::SpawnLaneItem(UArrowComponent* Lane) {
	// Decide On Chance
	const float RandomValue = FMath::FRandRange(0.0f, 1.0f);
	if (RandomValue <= 0.5f) {
		// Spawn Obstacle
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		const FTransform& SpawnTransform = Lane->GetComponentTransform();
		ACpp_Obstacle* Obstacle = GetWorld()->SpawnActor<ACpp_Obstacle>(SmallObstacleClass, SpawnTransform, SpawnParams);

	}
}

void ACpp_Floor::OnFloorTriggerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	// Check if the Other Actor is the player
	if (OtherActor->ActorHasTag("Player")) {
		GameModeRef->AddFloorTile(true);
		SetLifeSpan(2.0f);		
	}
}

