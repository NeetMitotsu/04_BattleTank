// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine.h"



void ATankPlayerController::BeginPlay() { 
	Super::BeginPlay();
	auto AimComp = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (AimComp)
	{
		FoundAimingComponent(AimComp);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't find AimComp"));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {

	if (!GetControlledTank()) { return; }


	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) { // Has "side-effect", is going to line trace
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get world location if linetrace through crosshait, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	// Find the crosshair position in pixel coordinates
	// 找到像素坐标中的十字线位置
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	// "De-project" the screen position of the crosshair to a world direction
	// 将十字线的屏幕位置投影到 世界方向？
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)){
		// Line-trace along that look direction, and see what we hit(up to max range)
		// 沿视线方向跟中， 看命中了什么（最大范围）
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraWorldLocation; // to be discarded 会被丢弃
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult, 
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		) {
		// Set hit location
		// 设置命中位置
		HitLocation = HitResult.Location;
		return true; 
	}
	HitLocation = FVector(0);
	return false; // Line trace didn't succeed
}
 