// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class AVENTYR_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	ACharacterBase();
	
	//Abilities 
	UPROPERTY(VisibleAnywhere, Category = "Abilities")
	class UCharacterAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Abilities|Attributes")
    class UBaseAttributeSet* AttributeSet;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
