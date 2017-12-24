// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponen.h"
#include "TankTrack.h"
#include "Engine.h"

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

void UTankMovementComponen::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) {
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	// 计算两个向量间的x方向间的单位向量积
	auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	//UE_LOG(LogTemp, Warning, TEXT("result : %f"), result)
	IntendMoveRigth(RightThrow);
	IntendMoveForward(ForwardThrow);
}


