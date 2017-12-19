// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponen.h"
#include "TankTrack.h"

void UTankMovementComponen::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponen::IntendMoveForward(float Throw) {
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward : %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponen::IntendMoveRigth(float Throw) {
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}


