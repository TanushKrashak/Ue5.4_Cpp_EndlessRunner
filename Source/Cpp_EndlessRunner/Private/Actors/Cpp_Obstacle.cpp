// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Cpp_Obstacle.h"

ACpp_Obstacle::ACpp_Obstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Setup Root
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	// Setup Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);


}

void ACpp_Obstacle::BeginPlay()
{
	Super::BeginPlay();

	
}


