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

public:
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Screen Crosshair")
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere, Category = "Screen Crosshair")
		float CrossHairYLocation = 0.33333;
	
	ATank* GetControlledTank() const;

	// Start the tank moving the barrell towards to where the crosshair points in the world
	void AimTowardsCrosshair();

	//return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
};
