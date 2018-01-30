// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UMG_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GETTINGTOKNOWYOU_API AUMG_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;

};
