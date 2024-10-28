// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AventyrCharacter.h"
#include "Characters/CombatComponent.h"
#include "Characters/EquipmentComponent.h"

AAventyrCharacter::AAventyrCharacter()
{
	EquipmentComponent  = CreateDefaultSubobject<UEquipmentComponent>("EquipmentComp");
	CombatComponent = CreateDefaultSubobject<UCombatComponent>("CombatComp");
}
