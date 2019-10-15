// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

private:

	// How close can the AI tank get to the player
	//UFUNCTION(BlueprintCallable, Category = Setup)
	float AcceptanceRadius = 3000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
