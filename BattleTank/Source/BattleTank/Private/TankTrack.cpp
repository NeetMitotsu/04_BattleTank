// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle) {
	// TODO clamp actual throttle value so player can't over-drive
	// TODO 控制实际的油门， 不能超速
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s ForceApplied : %f"), *ForceApplied.ToString(), Throttle);
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	
}

