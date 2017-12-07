// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine.h"



void UTankTurret::Elevate(float RelativeSpeed) {
	// 锁定速度
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	// 计算仰角
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	// 新仰角
	auto RawNewElevation = RelativeRotation.Raw + ElevationChange;
	// 锁定最大仰角
	// 设置模型仰角
	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}
