// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

//Macro for update Stats
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * Base Attribute set for all characters in game.
 */

UCLASS()
class AVENTYR_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
	void ClampData(const struct FGameplayEffectModCallbackData& Data);
	void AdjustDefaultAttributes(const FGameplayAttribute& Attribute, float& NewValue);

	UFUNCTION()
	void AdjustAttributeForMaxChange(
		FGameplayAttributeData& AffectedAttribute,
		const FGameplayAttributeData& MaxAttribute,
		float NewMaxValue,
		const FGameplayAttribute& AffectedAttributeProperty);

public:
	UBaseAttributeSet();
	
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	
	UPROPERTY(BlueprintReadOnly,Category="Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health)
	
	UPROPERTY(BlueprintReadOnly,Category="Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth)
	
	UPROPERTY(BlueprintReadOnly,Category="Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Stamina)
	
	UPROPERTY(BlueprintReadOnly,Category="Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStamina)
	
	UPROPERTY(BlueprintReadOnly,Category="Attributes")
	FGameplayAttributeData Exp;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Exp)
	
	UPROPERTY(BlueprintReadOnly,Category="Attributes")
	FGameplayAttributeData MaxExp;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxExp)
	
};
