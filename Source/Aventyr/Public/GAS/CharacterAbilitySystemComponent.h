// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CharacterAbilitySystemComponent.generated.h"

/**
 * Ability component
 */
UCLASS()
class AVENTYR_API UCharacterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	//Ptr 
	UPROPERTY()
	class ACharacterBase* OwnerPtr;

	UPROPERTY()
	AHUD* GameplayHUD;
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	int Level;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes")
	TArray<TSubclassOf<class UGameplayEffect>> DefaultAttributeEffects;

	//Default Effect
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void ApplyDefeaultAbilityEffects();
	
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void RemoveDefeaultAbilityEffects();

	//Default normal Attack
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void ApplyDefeaultAbilities();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category = "Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> NormalAttackAbilities;

	UPROPERTY(BlueprintReadOnly ,Category = "Abilities")
	TArray<FGameplayAbilitySpecHandle> NormalAttackAbilitiesSpecHanlde;
	
	//Handle Stats Change
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void HandleHealthChanged();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void HandleStaminaChanged();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void HandleXpChanged();

	
protected:
	virtual void BeginPlay() override;
	
};


   
