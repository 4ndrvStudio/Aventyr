// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CharacterAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class AVENTYR_API UCharacterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	UPROPERTY()
	class ACharacterBase* OwnerPtr;

	//Default Effect
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void ApplyDefeaultAbilityEffects();

	//Default Effect
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void RemoveDefeaultAbilityEffects();
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	int Level;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	TArray<TSubclassOf<class UGameplayEffect>> DefaultAttributeEffects;

protected:
	virtual void BeginPlay() override;

	
};


   
