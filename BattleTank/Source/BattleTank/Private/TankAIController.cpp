// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	/*ATank* AIPlayController = GetControlledTank();
	if (!AIPlayController) {
		UE_LOG(LogTemp, Warning, TEXT("Can't find AIPlayController a tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("find AIController: %s"), *AIPlayController->GetName());
	}
	ATank* AIPlayerTank = GetPlayerTank();
	if (!AIPlayController) {
		UE_LOG(LogTemp, Warning, TEXT("Can't find AIPlayerTank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Find AIPlayerTank: %s"), *(AIPlayerTank->GetName()));
	}*/
	

}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	MoveToActor(PlayerTank, AcceptanceRadius);
	//TODO Move towards the player
	// Aim towards the player
	// 转向玩家的坦克
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//ControlledTank->Fire();
}
