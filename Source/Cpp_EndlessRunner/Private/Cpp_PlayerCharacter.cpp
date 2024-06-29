// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"



ACpp_PlayerCharacter::ACpp_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));	
	SpringArm->TargetArmLength = 600.0f;
	SpringArm->SocketOffset = FVector(0.0f, 0.0f, 100.0f);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetupAttachment(RootComponent);

	// Setup Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false;
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);


}

void ACpp_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void ACpp_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Add Forward Movement (in tick as its an endless runner, take into acc delta time)
	AddMovementInput(GetActorForwardVector(), 100.0f * DeltaTime);

}
void ACpp_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveLeftAction, ETriggerEvent::Started, this, &ACpp_PlayerCharacter::MoveLeft);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Started, this, &ACpp_PlayerCharacter::MoveRight);
		EnhancedInputComponent->BindAction(MoveDownAction, ETriggerEvent::Started, this, &ACpp_PlayerCharacter::MoveDown);

	}
}

void ACpp_PlayerCharacter::ChangeLaneUpdate(float inAlpha) {

}
void ACpp_PlayerCharacter::ChangeLaneComplete() {

}

void ACpp_PlayerCharacter::MoveLeft() {

}
void ACpp_PlayerCharacter::MoveRight() {

}
void ACpp_PlayerCharacter::MoveDown() {

}

