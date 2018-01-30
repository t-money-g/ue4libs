// Fill out your copyright notice in the Description page of Project Settings.

#include "GettingToKnowYouGameModeBase.h"

void AGettingToKnowYouGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if(CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if(CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

// void AGettingToKnowYouGameModeBase::StartPlay()
// {
//     Super::StartPlay();
// 
//     if (GEngine)
//     {
//         // Display a debug message for five seconds
//         // The -1 "Key" value (first argument) indicates that we will never need to update or refresh this  message.
//         GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!" ));
//     }
// }

void AGettingToKnowYouGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
}
