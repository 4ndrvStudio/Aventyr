// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayHUD.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameplayHUD : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AVENTYR_API IGameplayHUD
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHPBar(float percent);
	UFUNCTION(BlueprintImplementableEvent)
	void  UpdateMPBar(float percent);
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateExpBar(float percent);
	
};
