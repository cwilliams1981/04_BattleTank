// Copyright cwil


#include "Public/Tank.h"

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	UE_LOG(LogTemp, Warning, TEXT("DamagePoints: %1"), DamagePoints);
	UE_LOG(LogTemp, Warning, TEXT("DamageToApply: %i"), DamageToApply);

	CurrentHealth -= DamageToApply;

	UE_LOG(LogTemp, Warning, TEXT("RemainingHealth: %i"), CurrentHealth);

	if (CurrentHealth <= 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("GameOver!!!"));
		TankDeathNotify.Broadcast();
	}

	return DamageToApply;
}