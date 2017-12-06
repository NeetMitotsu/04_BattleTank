// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	// Move the barrel the right amount this frame
	// 在当前帧移动适量的角度
	// Given a max elevation speed, and the frame time
	// 给定最大仰角速度和帧时间
	
	// 锁定速度
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	// 计算仰角
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	// 新仰角
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	// 锁定最大仰角
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	// 设置模型仰角
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}



