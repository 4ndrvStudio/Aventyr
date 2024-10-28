// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AventyrCharacter.h"
#include "GameplayAbilitySpecHandle.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AVENTYR_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

	//Ptr
	UPROPERTY()
	AAventyrCharacter* OwnerPtr;

	//Normal Attack List
	UPROPERTY(EditAnywhere, Category="Combat")
	TArray<UAnimMontage*> NormalAttacks;
	
	
	UPROPERTY(VisibleAnywhere)
	bool bCanDoAttack { true };

	UPROPERTY()
	int CurrentNormalAttackIndex { 0 } ; 
	
public:	
	// Sets default values for this component's properties
	UCombatComponent();
	
	//Execute Attack
	UFUNCTION(BlueprintCallable, Category="Combat")
	void ExecuteNormalAttack();

	UFUNCTION(BlueprintCallable, Category="Combat")
	void HandleResetComboAttack();

	UFUNCTION(BlueprintCallable, Category="Combat")
	bool IsActiveNormalAttackAbility();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
