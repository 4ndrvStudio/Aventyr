// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "AventyrCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AVENTYR_API AAventyrCharacter : public ACharacterBase
{
	GENERATED_BODY()

	

protected:
	AAventyrCharacter();


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UEquipmentComponent* EquipmentComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCombatComponent* CombatComponent;
	
};
