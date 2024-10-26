// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AventyrCharacter.h"

#include "Characters/Equipment.h"

AAventyrCharacter::AAventyrCharacter()
{
	Equipment  = CreateDefaultSubobject<UEquipment>("EquipmentComp");
}
