// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponen.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UTankMovementComponen : public UNavMovementComponent
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = Setup)
	void IntendMoveForward(float Throw);
	
	
};
