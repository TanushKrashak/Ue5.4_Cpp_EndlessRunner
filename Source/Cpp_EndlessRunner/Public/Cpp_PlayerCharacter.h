// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cpp_PlayerCharacter.generated.h"

// Forward Declarations
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class ACpp_GM_EndlessRunner;

UCLASS()
class CPP_ENDLESSRUNNER_API ACpp_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	// Lanes
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Lanes")
	int32 CurrentLane = 1;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Lanes")
	int32 TargetLane = 0;



	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	ACpp_PlayerCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Lane Changing
	UFUNCTION(BlueprintImplementableEvent, Category ="Lane")
	void ChangeLane();
	UFUNCTION(BlueprintCallable, Category = "Lane")
	void ChangeLaneUpdate(float inAlpha);
	UFUNCTION(BlueprintCallable, Category = "Lane")
	void ChangeLaneComplete();

protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	// Input Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveLeftAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveRightAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveDownAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY(VisibleInstanceOnly)
	ACpp_GM_EndlessRunner* GameModeRef;


	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	UFUNCTION()
	void MoveLeft();
	UFUNCTION()
	void MoveRight();
	UFUNCTION()
	void MoveDown();

};
