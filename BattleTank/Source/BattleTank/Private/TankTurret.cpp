// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine.h"



void UTankTurret::Elevate(float RelativeSpeed) {
	// 锁定速度
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	// 计算旋转角度
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	// 新角度
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;
	// 设置模型旋转
	SetRelativeRotation(FRotator(0, 0, RawNewElevation));
}
