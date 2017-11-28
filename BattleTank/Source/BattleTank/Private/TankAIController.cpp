// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Engine.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	ATank* AIPlayController = GetAIController();
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
	}

}

ATank* ATankAIController::GetAIController() const{
	return Cast<ATank> (GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) {
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);

}
