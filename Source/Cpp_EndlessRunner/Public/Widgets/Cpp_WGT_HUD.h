// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cpp_WGT_HUD.generated.h"

// Forward Declarations
class UTextBlock;
class UButton;

UCLASS()
class CPP_ENDLESSRUNNER_API UCpp_WGT_HUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void UpdateCoinsCollected(const int32 Coins);

	UFUNCTION()
	void UpdateHealth(const int32 Health);

protected:
	//================================================================================================================
	// PROPERTIES & VARIABLES
	//================================================================================================================
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TXT_CoinsCollected;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TXT_Health;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* BTN_Pause;

	//================================================================================================================
	// FUNCTIONS
	//================================================================================================================
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void OnPauseClicked();


};
