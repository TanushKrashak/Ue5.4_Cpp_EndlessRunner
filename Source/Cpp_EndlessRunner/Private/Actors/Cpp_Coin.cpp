// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Cpp_Coin.h"

ACpp_Coin::ACpp_Coin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ACpp_Coin::BeginPlay()
{
	Super::BeginPlay();

	
}
void ACpp_Coin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

