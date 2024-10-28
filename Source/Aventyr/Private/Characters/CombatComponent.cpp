// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CombatComponent.h"
#include "Characters/EquipmentComponent.h"
#include "GAS/CharacterAbilitySystemComponent.h"
#include "GameplayAbilitySpecHandle.h"
#include "GAS/GANormalAttack_Montage.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerPtr = Cast<AAventyrCharacter>(GetOwner());

	bCanDoAttack = true;
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCombatComponent::ExecuteNormalAttack()
{
	AActor* EquippedWeapon = OwnerPtr -> EquipmentComponent->EquippedWeapon;
	if(!bCanDoAttack || !IsValid(EquippedWeapon)) return;
    
    const TArray<FGameplayAbilitySpecHandle>& NormalAttackAbilitiesSpecHanlde = OwnerPtr -> AbilitySystemComponent -> NormalAttackAbilitiesSpecHanlde;

	const FGameplayAbilitySpecHandle& AbilitySpecHandle = NormalAttackAbilitiesSpecHanlde[CurrentNormalAttackIndex];

	bool bHasActived = OwnerPtr -> AbilitySystemComponent -> TryActivateAbility(AbilitySpecHandle);

	bCanDoAttack = !bHasActived;
	
	CurrentNormalAttackIndex = CurrentNormalAttackIndex >= NormalAttackAbilitiesSpecHanlde.Num() -1 ? 0 : CurrentNormalAttackIndex+=1;
}


void UCombatComponent::HandleResetComboAttack()
{
	bCanDoAttack = true;
	TArray<FGameplayAbilitySpec> ActiveAbilitySpecs = OwnerPtr -> AbilitySystemComponent-> GetActivatableAbilities();
	for(FGameplayAbilitySpec& Spec : ActiveAbilitySpecs)
	{
		 TArray<UGameplayAbility*> AbilitiesInstance = Spec.GetAbilityInstances();
			for (UGameplayAbility* Ability : AbilitiesInstance)
			{
				if (Ability)
				{
					UGANormalAttack_Montage* NormalAttackAbility = Cast<UGANormalAttack_Montage>(Ability);
					if (NormalAttackAbility)
					{
						NormalAttackAbility->OnMontageEnded(false);
					}
				}
			}
	}
}

bool UCombatComponent::IsActiveNormalAttackAbility()
{
	TArray<FGameplayAbilitySpec> ActiveAbilitySpecs = OwnerPtr -> AbilitySystemComponent-> GetActivatableAbilities();
	for(FGameplayAbilitySpec& Spec : ActiveAbilitySpecs)
	{
		TArray<UGameplayAbility*> AbilitiesInstance = Spec.GetAbilityInstances();
		for (UGameplayAbility* Ability : AbilitiesInstance)
		{
			if (Ability)
			{
				UGANormalAttack_Montage* NormalAttackAbility = Cast<UGANormalAttack_Montage>(Ability);
				if (NormalAttackAbility)
				{
					return true;
				}
			}
		}
	}

	return false;
}

