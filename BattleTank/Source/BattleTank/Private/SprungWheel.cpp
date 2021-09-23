// Copyright Cwil

#include "SprungWheel.h"


// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	SetRootComponent(Mass);
	//Mass->SetSimulatePhysics(true);


	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("MassWheelConstraint"));
	MassWheelConstraint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//Spring->SetLinearPositionDrive(false, false, true);
	//Spring->SetLinearPositionTarget(FVector(0.0f,0.0f,0.0f));
	//Spring->SetLinearDriveParams(5000.0f, 2000.0f, 0.0f);
	//Spring->SetLinearZLimit(LCM_Free,0.0f);
	//Spring->SetAngularSwing1Limit(ACM_Locked, 0.0f);
	//Spring->SetAngularSwing2Limit(ACM_Locked, 0.0f);
	//Spring->SetAngularTwistLimit(ACM_Locked, 0.0f);
	//Spring->ComponentName1  FName("Upper Strut");


	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

