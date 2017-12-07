// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine.h"



void UTankTurret::Elevate(float RelativeSpeed) {
	// �����ٶ�
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	// ��������
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	// ������
	auto RawNewElevation = RelativeRotation.Raw + ElevationChange;
	// �����������
	// ����ģ������
	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}
