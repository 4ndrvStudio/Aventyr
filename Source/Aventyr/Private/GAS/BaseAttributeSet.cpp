// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/BaseAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Characters/CharacterBase.h"
#include "GAS/CharacterAbilitySystemComponent.h"


UBaseAttributeSet::UBaseAttributeSet()
{
	
}

void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	ClampData(Data);
}


void UBaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	//Adjust when level change or set default
	AdjustDefaultAttributes(Attribute,NewValue);
}


void UBaseAttributeSet::ClampData(const struct FGameplayEffectModCallbackData& Data)
{
	ACharacterBase* CharacterBase = Cast<ACharacterBase>(GetOwningActor());
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));

		if(CharacterBase)
			CharacterBase -> AbilitySystemComponent -> HandleHealthChanged();
	}
	
	if(Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.0f, GetMaxStamina()));

		if(CharacterBase)
			CharacterBase -> AbilitySystemComponent -> HandleStaminaChanged();
	}

	if(Data.EvaluatedData.Attribute == GetExpAttribute())
	{
		SetExp(FMath::Clamp(GetExp(), 0.0f, GetMaxExp()));

		if(CharacterBase)
			CharacterBase -> AbilitySystemComponent -> HandleXpChanged();
	}
}

void UBaseAttributeSet::AdjustDefaultAttributes(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetMaxHealthAttribute())
	{
		AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
	}

	if (Attribute == GetMaxStaminaAttribute())
	{
		AdjustAttributeForMaxChange(Stamina, MaxStamina, NewValue, GetStaminaAttribute());
	}
}

void UBaseAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* AbilitySystemComponent = GetOwningAbilitySystemComponent();
	float CurrentMaxValue = MaxAttribute.GetCurrentValue(); 
	if(!FMath::IsNearlyEqual(CurrentMaxValue,NewMaxValue) && AbilitySystemComponent)
	{
		AbilitySystemComponent -> ApplyModToAttributeUnsafe(AffectedAttributeProperty,EGameplayModOp::Additive, NewMaxValue);
	}
}



