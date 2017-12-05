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
	// �����ٶ�
	FVector OutLaunchVelocity;
	// ��ʼλ��
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// ���㵽��ָ��λ��������ٶ�����OutLaunchVelocity��x, y, z�� 
	// 
	bool bHaveAimSolusion = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,// ����λ��
		LaunchSpeed,// ���ٶ�
		false,// �Ƿ�Ϊ���ߣ�
		//0,// ��ײ�뾶
		//0,//����
		ESuggestProjVelocityTraceOption::DoNotTrace // ����ѡ��
	);
	
	if (bHaveAimSolusion) { // Calculate the OutLaunchVelocity
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"),*TankName, *AimDirection.ToString());
	}
	// if no solusion found do nothing
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet) {
	this->Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	// Work-out difference between current barrel rotation, and AimDirection
	// ���㵱ǰ��̨��AimDirection֮�䣬��Ҫ��ת�ĽǶ�
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator : %s"), *DeltaRotator.ToString());
	
	Barrel->Elevate(5);


}
