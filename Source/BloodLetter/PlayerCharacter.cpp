// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceJump += DeltaTime;

	//If the player is pressing Jump and hasn't already released Jump
	if (bIsHoldingJump && !bHasReleasedJump) {
		TimeHoldingJump += DeltaTime;
		HoldJump();
	}
	else {
		timeSinceReleaseJump += DeltaTime;
		if (timeSinceReleaseJump < 0.25f) {
			GetCharacterMovement()->GravityScale = 1.2f;
			//Slightly lower the horizontal velocity
			GetCharacterMovement()->Velocity.Y *= .98f;
		}
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Reads player movement
	InputComponent->BindAxis("Right", this, &APlayerCharacter::MoveRight);

	//Reads jump input
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::ReleaseJump);
}

void APlayerCharacter::MoveRight(float AxisValue)
{
	if (AxisValue != 0) {
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, AxisValue);
	}
}

void APlayerCharacter::Jump()
{
	bIsHoldingJump = true;
	bHasReleasedJump = false;

	//if the player has not jumped
	if (!bHasJumped) {
		LaunchCharacter({ 0, 0, 550 }, false, true);
		TimeSinceJump = 0;
		bHasJumped = true;
	}
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString("Jump Pressed"));
}

void APlayerCharacter::HoldJump()
{
	//If the player has not already completed a jump
	if (!bHasReleasedJump) {
		//If Jump hasn't been held for too long
		if (TimeHoldingJump < .3f) {
			//Add a bit more height to the jump by lowering gravity
			GetCharacterMovement()->GravityScale = 0.4;
			//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString("Jumping"));
		}
		//If the player has been holding Jump for too long
		else if (TimeHoldingJump > .75f) {
			GetCharacterMovement()->GravityScale = 0.8f;
			bIsHoldingJump = false;
		}
	}
}

void APlayerCharacter::ReleaseJump()
{
	TimeHoldingJump = 0;
	bIsHoldingJump = false;
	bHasReleasedJump = true;
	GetCharacterMovement()->GravityScale = 1;
	timeSinceReleaseJump = 0;
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString("Jump Released"));
}

void APlayerCharacter::Landed(const FHitResult& hit)
{
	ACharacter::Landed(hit);
	GetCharacterMovement()->GravityScale = 1;
	bHasJumped = false;
}

