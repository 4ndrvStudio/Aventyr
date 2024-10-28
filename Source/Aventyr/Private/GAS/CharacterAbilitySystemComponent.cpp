// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CharacterAbilitySystemComponent.h"
#include "Characters/CharacterBase.h"
#include "GameFramework/HUD.h"
#include "GAS/BaseAttributeSet.h"
#include "Interfaces/GameplayHUD.h"

void UCharacterAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerPtr = Cast<ACharacterBase>(GetOwner());

	APlayerController* PlayerController = Cast<APlayerController>(OwnerPtr->GetController());
	GameplayHUD = PlayerController ->GetHUD();

	//Setup Default UI
	HandleHealthChanged();
	HandleStaminaChanged();
	HandleXpChanged();

	//ApplyDefaultAbilities
	ApplyDefeaultAbilities();
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

void UCharacterAbilitySystemComponent::ApplyDefeaultAbilities()
{
	//Apply normal Attack
	for(TSubclassOf<UGameplayAbility> NormalAbility : NormalAttackAbilities)
	{
		FGameplayAbilitySpecHandle NormalAbilitySpecHandle = OwnerPtr-> AbilitySystemComponent -> GiveAbility(FGameplayAbilitySpec(NormalAbility,Level,INDEX_NONE,this));
		NormalAttackAbilitiesSpecHanlde.Add(NormalAbilitySpecHandle);
	}
}

void UCharacterAbilitySystemComponent::HandleHealthChanged()
{
	if(!GameplayHUD || !GameplayHUD -> GetClass() -> ImplementsInterface(UGameplayHUD::StaticClass())) return;
	float Percent = OwnerPtr -> AttributeSet->GetHealth() / OwnerPtr -> AttributeSet->GetMaxHealth();
	IGameplayHUD::Execute_UpdateHPBar(GameplayHUD,Percent);
}

void UCharacterAbilitySystemComponent::HandleStaminaChanged()
{
	if(!GameplayHUD || !GameplayHUD -> GetClass() -> ImplementsInterface(UGameplayHUD::StaticClass())) return;
	
	float Percent = OwnerPtr -> AttributeSet->GetStamina() / OwnerPtr -> AttributeSet->GetMaxStamina();
	IGameplayHUD::Execute_UpdateMPBar(GameplayHUD,Percent);
	
}

void UCharacterAbilitySystemComponent::HandleXpChanged()
{
	if(!GameplayHUD || !GameplayHUD -> GetClass() -> ImplementsInterface(UGameplayHUD::StaticClass())) return;
	float Percent = OwnerPtr -> AttributeSet->GetExp() / OwnerPtr -> AttributeSet->GetMaxExp();
	IGameplayHUD::Execute_UpdateExpBar(GameplayHUD,Percent);
}
