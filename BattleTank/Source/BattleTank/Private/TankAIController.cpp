// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	ATank* AIPlayController = GetAIController();
	if (!AIPlayController) {
		UE_LOG(LogTemp, Warning, TEXT("Can't find AIPlayController a tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("find AIController: %s"), *AIPlayController->GetName());
	}
}

ATank* ATankAIController::GetAIController() const{
	return Cast<ATank> (GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const {


	return nullptr;
}
