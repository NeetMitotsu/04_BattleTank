// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward declarations
class UTankAimingComponent;

/**
 *  
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
protected:

	UFUNCTION(BlueprintImplementableEvent, category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	// Start the tank moving the barrel so that a shot would it where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5F;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.3333F;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange  = 1000000.F;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
