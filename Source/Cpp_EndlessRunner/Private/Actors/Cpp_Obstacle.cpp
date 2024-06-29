// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Cpp_Obstacle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Cpp_PlayerCharacter.h"


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
	Mesh->OnComponentHit.AddDynamic(this, &ACpp_Obstacle::OnMeshHit);

}

void ACpp_Obstacle::OnMeshHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if (auto Player = Cast<ACpp_PlayerCharacter>(OtherActor)) {
		Player->Death();
	}
}


