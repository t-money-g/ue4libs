// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "GettingToKnowYouGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GETTINGTOKNOWYOU_API AGettingToKnowYouGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public: 
    /** Remove the current menu widget and ceate a new one from the specified class , if provided. */
    UFUNCTION(BlueprintCallable, Category = "UMG Game")
    void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:

/** Called wen the game starts. */
//	virtual void StartPlay() override;

    virtual void BeginPlay() override;

    /** The widget class we will uses as our menu when the game starts . */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
    TSubclassOf<UUserWidget>StartingWidgetClass;

    /** The widget instance that we are using as our menu. */
    UPROPERTY()
    class UUserWidget* CurrentWidget;
	
};
