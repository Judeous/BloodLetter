#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class BLOODLETTER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UFUNCTION(BlueprintCallable)
	//	void MoveForward(float AxisValue);

	UFUNCTION(BlueprintCallable)
		void MoveRight(float AxisValue);

	void Jump();
	void HoldJump();
	void ReleaseJump();
	virtual void Landed(const FHitResult& hit) override;

	//MainMenu (Can be pause menu later)
	void OpenMenu();

private:
	//Need reference to controller for UI purposes
	APlayerController* _playerController = nullptr;

	float TimeHoldingJump = 0;
	bool bIsHoldingJump = false;
	bool bHasJumped = false;
	bool bHasReleasedJump = false;
	int JumpLimit = 3;
	float TimeSinceJump = 900;
	float JumpLimitTime = 0.25f;
	float timeSinceReleaseJump = 0;
};
