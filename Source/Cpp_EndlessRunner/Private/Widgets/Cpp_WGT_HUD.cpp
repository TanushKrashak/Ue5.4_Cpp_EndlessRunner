// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Cpp_WGT_HUD.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"


void UCpp_WGT_HUD::UpdateCoinsCollected(const int32 Coins) {
	TXT_CoinsCollected->SetText(FText::FromString(FString::FromInt(Coins)));
}


void UCpp_WGT_HUD::UpdateHealth(const int32 Health) {
	TXT_Health->SetText(FText::FromString(FString::FromInt(Health)));
}

void UCpp_WGT_HUD::NativeConstruct() {
	Super::NativeConstruct();

	if (BTN_Pause) {
		BTN_Pause->OnClicked.AddDynamic(this, &UCpp_WGT_HUD::OnPauseClicked);
	}
}


void UCpp_WGT_HUD::OnPauseClicked() {
	// Pause Game and Unpause when clicked again
	if (UGameplayStatics::IsGamePaused(GetWorld())) {
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		// Set Input Mode Game & UI
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PlayerController) {
			FInputModeGameOnly InputMode;
			PlayerController->SetInputMode(InputMode);
		}
		return;
	}
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}


