// Fill out your copyright notice in the Description page of Project Settings.

#include "UMG_PlayerController.h"




void AUMG_PlayerController::BeginPlay()
{
    Super::BeginPlay();
    SetInputMode(FInputModeGameAndUI());
}
