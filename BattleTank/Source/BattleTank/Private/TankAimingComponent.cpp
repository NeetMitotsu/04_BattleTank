// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Engine.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
	if (!Barrel) {
		return;
	}
	// 发射速度
	FVector OutLaunchVelocity;
	// 开始位置
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// 计算到达指向位置所需的速度向量OutLaunchVelocity（x, y, z） 
	// 
	bool bHaveAimSolusion = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,// 到达位置
		LaunchSpeed,// 初速度 
		false,// 是否为弧线？
		0,// 碰撞半径
		0,//重力
		ESuggestProjVelocityTraceOption::DoNotTrace // 跟踪选项
	);
	
	if (bHaveAimSolusion) { // Calculate the OutLa unchVelocity
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"),*TankName, *AimDirection.ToString());
	} else {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
	}
	// if no solusion found do nothing
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet) {
	this->Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	// Work-out difference between current barrel rotation, and AimDirection
	// 计算当前炮台和AimDirection之间，需要旋转的角度
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	// UE_LOG(LogTemp, Warning, TEXT("AimAsRotator : %s"), *DeltaRotator.ToString());
	
	Barrel->Elevate(DeltaRotator.Pitch);


}
