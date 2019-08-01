// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ATank* GetControlledTank() const;

	virtual void Tick(float DeltaTime) override;
	
	// Start the tank moving the barrell towards to where the crosshair points in the world
	void AimTowardsCrosshair();
	
};
