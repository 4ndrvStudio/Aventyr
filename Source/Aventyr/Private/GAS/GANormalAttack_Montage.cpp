// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GANormalAttack_Montage.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "Animation/AnimInstance.h"


void UGANormalAttack_Montage::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{

	bool bIsCommit = CommitAbility(Handle,ActorInfo,ActivationInfo);

	if(bIsCommit)
	 {
		if(USkeletalMeshComponent* MeshComponent = ActorInfo->SkeletalMeshComponent.Get())
	 	{
	 		UAnimInstance* AnimInstance = MeshComponent->GetAnimInstance();
	 		if(AnimInstance)
	 		{
	 			FOnMontageEnded MontageEndedDelegate;
	 			MontageEndedDelegate.BindUObject(this, &UGANormalAttack_Montage::OnMontageEnded);
	 	
	 			AnimInstance->Montage_Play(MontageToPlay, PlayRate);
	 			AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate);
	 		}
	 	}
	 }
}

void UGANormalAttack_Montage::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, bInterrupted);
}

void UGANormalAttack_Montage::OnMontageEnded(bool bInterrupted)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, bInterrupted);
}

