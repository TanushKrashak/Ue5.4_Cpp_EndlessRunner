// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_Coin.generated.h"

// Forward Declarations
class USceneComponent;
class UStaticMeshComponent;
class USphereComponent;
class URotatingMovementComponent;
class USoundBase;

UCLASS()
class CPP_ENDLESSRUNNER_API ACpp_Coin : public AActor
{
	GENERATED_BODY()
	
public:	
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================



	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	ACpp_Coin();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	URotatingMovementComponent* RotatingMovement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
	USoundBase* CoinSound;

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
};
