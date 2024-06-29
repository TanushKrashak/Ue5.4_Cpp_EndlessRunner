// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cpp_WGT_HUD.generated.h"

class UTextBlock;

UCLASS()
class CPP_ENDLESSRUNNER_API UCpp_WGT_HUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void UpdateCoinsCollected(const int32 Coins);

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TXT_CoinsCollected;
	
};
