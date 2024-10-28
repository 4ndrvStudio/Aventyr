// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility_Montage.h"
#include "GANormalAttack_Montage.generated.h"

/**
 * 
 */
UCLASS()
class AVENTYR_API UGANormalAttack_Montage : public UGameplayAbility_Montage
{
	GENERATED_BODY()
	
public:
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void OnMontageEnded(UAnimMontage* Montage,bool bInterrupted);
	virtual void OnMontageEnded(bool bInterrupted);

};
