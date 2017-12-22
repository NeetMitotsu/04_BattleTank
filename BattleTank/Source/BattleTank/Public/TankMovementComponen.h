// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponen.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponen : public UNavMovementComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveRigth(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
private:

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
