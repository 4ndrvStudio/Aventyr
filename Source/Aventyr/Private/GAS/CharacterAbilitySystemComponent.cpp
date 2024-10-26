// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CharacterAbilitySystemComponent.h"
#include "Characters/CharacterBase.h"


void UCharacterAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerPtr = Cast<ACharacterBase>(GetOwner());
}


void UCharacterAbilitySystemComponent::ApplyDefeaultAbilityEffects()
{
	FGameplayEffectContextHandle EffectContext = MakeEffectContext();
	EffectContext.AddSourceObject(OwnerPtr);

	for(const TSubclassOf<UGameplayEffect> AttributeEffect : DefaultAttributeEffects)
	{
		FGameplayEffectSpecHandle EffectSpec = MakeOutgoingSpec(AttributeEffect,Level, EffectContext);
		if(EffectSpec.IsValid())
			ApplyGameplayEffectSpecToSelf(*EffectSpec.Data.Get());
	}
}

void UCharacterAbilitySystemComponent::RemoveDefeaultAbilityEffects()
{
	FGameplayEffectQuery Query;
	Query.EffectSource = OwnerPtr;
	RemoveActiveEffects(Query);
}
