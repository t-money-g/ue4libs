// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "FPSCharacter.generated.h"

UCLASS()
class GETTINGTOKNOWYOU_API AFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // FPS camera .
    UPROPERTY(VisibleAnywhere)
    class UCameraComponent* FPSCameraComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles input for moving forward and backward.
    UFUNCTION()
    void MoveForward(float Value);

    //Handles input for moving right and left.
    UFUNCTION()
    void MoveRight(float Value);

    UFUNCTION()
    void StartJump();

    // Clears jump flag when key is released 
    UFUNCTION()
    void StopJump();


    // First-person mech (arms) , visible only to the owning player. 
    UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
    class USkeletalMeshComponent* FPSMesh;


};
