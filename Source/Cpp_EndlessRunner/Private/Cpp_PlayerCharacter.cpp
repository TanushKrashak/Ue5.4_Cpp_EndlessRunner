// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Core/Cpp_GM_EndlessRunner.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


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

	// Get GameMode Reference
	GameModeRef = Cast<ACpp_GM_EndlessRunner>(GetWorld()->GetAuthGameMode());
	
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
	FVector NewLocation = GetActorLocation();
	NewLocation.Y = FMath::Lerp(GameModeRef->GetLaneOffset(CurrentLane), GameModeRef->GetLaneOffset(TargetLane), inAlpha);
	SetActorLocation(NewLocation);
}
void ACpp_PlayerCharacter::ChangeLaneComplete() {
	CurrentLane = TargetLane;
}

void ACpp_PlayerCharacter::Death() {
	if (!RestartTimerHandle.IsValid()) {
		const FVector Location = GetActorLocation();
		const auto World = GetWorld();
		// Play Death Effects
		if (DeathParticles) {
			UGameplayStatics::SpawnEmitterAtLocation(World, DeathParticles, Location, FRotator::ZeroRotator, true);
		}
		if (DeathSound) {
			UGameplayStatics::PlaySoundAtLocation(World, DeathSound, Location);
		}
		// Hide Mesh
		GetMesh()->SetVisibility(false);
		World->GetTimerManager().SetTimer(RestartTimerHandle, this, &ACpp_PlayerCharacter::onDeath, 2.0f, false);
	}
}

void ACpp_PlayerCharacter::CoinCollected() {
	GameModeRef->CoinCollected();
	// Can add cosmetic effects here
}

void ACpp_PlayerCharacter::onDeath() {
	// Restart Level
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void ACpp_PlayerCharacter::MoveLeft() {
	TargetLane = FMath::Clamp(TargetLane - 1, 0, 2);
	ChangeLane();
}
void ACpp_PlayerCharacter::MoveRight() {
	TargetLane = FMath::Clamp(TargetLane + 1, 0, 2);
	ChangeLane();
}
void ACpp_PlayerCharacter::MoveDown() {
	// Jump Down only if falling
	if (GetCharacterMovement()->IsFalling()) {
		GetCharacterMovement()->Velocity.Z = MoveDownSpeed;
	}
}

