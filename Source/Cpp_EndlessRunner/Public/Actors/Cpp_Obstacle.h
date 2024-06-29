// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_Obstacle.generated.h"

// Forward Declarations
class USceneComponent;
class UStaticMeshComponent;


UCLASS()
class CPP_ENDLESSRUNNER_API ACpp_Obstacle : public AActor
{
	GENERATED_BODY()
	
public:		
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================



	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	ACpp_Obstacle();
	
	virtual void BeginPlay() override;
	

protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
};
