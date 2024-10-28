// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AVENTYR_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

	//Ptr
	UPROPERTY(VisibleDefaultsOnly)
	USkeletalMeshComponent* MeshPtr;
	
	
	
public:	
	// Sets default values for this component's properties
	UEquipmentComponent();

	UPROPERTY(BlueprintReadOnly)
	bool bIsEquipped {false};

	UPROPERTY(BlueprintReadOnly)
	AActor* EquippedWeapon {nullptr};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category= "Equipments")
	TSubclassOf<AActor> BPWeapon;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, category= "Equipments")
	FName RightHandSocketName;
	
	UFUNCTION(BlueprintCallable, category= "Equipments")
	void Equip();

	UFUNCTION(BlueprintCallable, category= "Equipments")
	void Unequip();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
