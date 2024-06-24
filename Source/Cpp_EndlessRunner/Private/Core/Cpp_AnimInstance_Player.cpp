// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Cpp_AnimInstance_Player.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/Character.h"


void UCpp_AnimInstance_Player::NativeInitializeAnimation() {
	Super::NativeInitializeAnimation();
	// Setup Pawn
	if (Pawn == nullptr) {
		Pawn = TryGetPawnOwner();		
	}
	// Setup Movement Component
	if (Pawn) {
		MovementComponent = Pawn->GetMovementComponent();
	}
}
void UCpp_AnimInstance_Player::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);
	// Update Speed and bIsInAir
	if (Pawn && MovementComponent) {
		bIsInAir = MovementComponent->IsFalling();
		Speed = MovementComponent->Velocity.Size();
	}
}
