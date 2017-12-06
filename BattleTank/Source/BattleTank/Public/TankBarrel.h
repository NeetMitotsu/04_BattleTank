// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


/**
 * hidecategories 隐藏类别：指定分类将在ue编辑器属性里不可见
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 is max up movement
	// -1 表示最大向下速度， +1 表示最大向上速度 relativeSpeed 相对速度
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5;// Sensible default
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;
};
