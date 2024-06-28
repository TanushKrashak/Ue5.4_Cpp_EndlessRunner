// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Cpp_Floor.h"

ACpp_Floor::ACpp_Floor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ACpp_Floor::BeginPlay()
{
	Super::BeginPlay();

	
}
void ACpp_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

