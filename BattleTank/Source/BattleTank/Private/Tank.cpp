// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankMovementComponen.h"
#include "Engine.h"
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: c++ constract"), *TankName);
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

	/*TankMovementComponent = CreateDefaultSubobject<UTankMovementComponen>(FName("Movement Component"));*/
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector HitLocation) {
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

//void ATank::SetBarrelReference(UTankBarrel * BarrelToSet) {
//	TankAimingComponent->SetBarrelReference(BarrelToSet);
//	Barrel = BarrelToSet;
//}
//
//void ATank::SetTurretReference(UTankTurret* TurretToset) {
//	TankAimingComponent->SetTurretReference(TurretToset);
//}

void ATank::Fire() {

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded) { 
		// Spawn a projectile at the socket location on the barrel
		// 在socket位置生成抛射体
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		
	}

	
}




