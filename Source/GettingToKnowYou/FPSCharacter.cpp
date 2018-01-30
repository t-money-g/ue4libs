// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacter.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create a first person camera component 
    FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
   
    //Attach the camera compoent to our capsurle component.
    FPSCameraComponent->SetupAttachment(GetRootComponent());

    //POsition the camera slightly above the eyes.
    FPSCameraComponent->SetRelativeLocation(FVector(0.0f,0.0f, 50.0f + BaseEyeHeight));

    //Allow the pawn to control camera rotation.
    FPSCameraComponent->bUsePawnControlRotation = true;


    //Create a first person mesh component for the owning player.
    FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));

    //Only the owning player sees the mesh.
    FPSMesh->SetupAttachment(FPSCameraComponent);

    // Attach the FPS mesh to the FPS camera. 
    FPSMesh->bCastDynamicShadow = false;
    FPSMesh->CastShadow = false;

    GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

    if (GEngine)
    {
        //  Put up a debug message for five seconds. The -1 "Key" value (first argumet) indicates we will never need to update this message 
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));

    }
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Set up "movement" binding. 
    PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

    // Set up "look" bindings
    PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);

    // Set up "action" bindings
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);

}

void AFPSCharacter::MoveForward(float Value)
{

    // Find out which way is "fowrad" and record that the player wants to move this way 
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value);

}


void AFPSCharacter::MoveRight(float Value)
{

    //Find out which way is "right" and record that the player wants to the move this way 
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}

void AFPSCharacter::StartJump()
{
    bPressedJump = true;
}

void AFPSCharacter::StopJump()
{
    bPressedJump = false;
}