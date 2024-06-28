// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_Floor.generated.h"

// Forward Declarations
class USceneComponent;
class UStaticMeshComponent;
class UArrowComponent;
class UBoxComponent;

UCLASS()
class CPP_ENDLESSRUNNER_API ACpp_Floor : public AActor
{
	GENERATED_BODY()
	
public:		
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* FloorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* AttachPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* CenterLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* LeftLane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* RightLane;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floor")
	UBoxComponent* FloorTrigger;

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	ACpp_Floor();


protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================


	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};