// Copyright cwil

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 * Responsible for helping the player aim
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

	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Screen Crosshair")
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly, Category = "Screen Crosshair")
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly, Category = "Trace Range")
	float LineTraceRange = 1000000.0f; // Maximum range of Tank view for line trace.

	// Start the tank moving the barrell towards to where the crosshair points in the world
	void AimTowardsCrosshair();

	// Return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
