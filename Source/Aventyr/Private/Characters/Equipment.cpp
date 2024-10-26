// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Equipment.h"

// Sets default values for this component's properties
UEquipment::UEquipment()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UEquipment::BeginPlay()
{
	Super::BeginPlay();
	// ...
	MeshPtr = GetOwner() -> FindComponentByClass<USkeletalMeshComponent>();
	
}


// Called every frame
void UEquipment::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEquipment::Equip()
{
	if(!MeshPtr) return;

	EquippedWeapon = GetWorld() -> SpawnActor(BPWeapon);

	FAttachmentTransformRules TransformRules = FAttachmentTransformRules(
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::KeepRelative,
		true);
	
	EquippedWeapon->AttachToComponent(MeshPtr,TransformRules,RightHandSocketName);

	bIsEquipped = true;
}

void UEquipment::Unequip()
{
	if(!MeshPtr || EquippedWeapon == nullptr ) return;

	GetWorld() -> DestroyActor(EquippedWeapon);
	
	bIsEquipped = false;
}



