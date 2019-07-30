// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	FString	ControlledTank = GetControlledTank()->GetName();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing Tank: %s"), *ControlledTank)
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing Tank"))
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}