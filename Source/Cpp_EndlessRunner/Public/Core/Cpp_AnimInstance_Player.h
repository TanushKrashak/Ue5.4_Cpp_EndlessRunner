// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Cpp_AnimInstance_Player.generated.h"

// Forward Declarations
class APawn;
class UPawnMovementComponent;

UCLASS()
class CPP_ENDLESSRUNNER_API UCpp_AnimInstance_Player : public UAnimInstance
{
	GENERATED_BODY()
	

public:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================


	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;



protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Movement")
	float Speed;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Movement")
	bool bIsInAir;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Movement")
	APawn* Pawn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Movement")
	UPawnMovementComponent* MovementComponent;

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
};
