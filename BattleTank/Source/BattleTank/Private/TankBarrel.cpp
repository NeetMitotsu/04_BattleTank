// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed) {
	UE_LOG(LogTemp, Warning, TEXT("DegreesPerSecond: %f"), RelativeSpeed);
	
	// Move the barrel the right amount this frame
	// 在当前帧移动适量的角度

	// Given a max elevation speed, and the frame time
	// 给定最大仰角速度和帧时间

}



