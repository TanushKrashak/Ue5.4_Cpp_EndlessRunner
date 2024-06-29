// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Cpp_WGT_HUD.h"
#include "Components/TextBlock.h"

void UCpp_WGT_HUD::UpdateCoinsCollected(const int32 Coins) {
	TXT_CoinsCollected->SetText(FText::FromString(FString::FromInt(Coins)));
}
