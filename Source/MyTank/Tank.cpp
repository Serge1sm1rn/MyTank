// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	RootComponent = Collision;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("BodyMesh");
	BodyMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("TurretMesh");
	TurretMesh->SetupAttachment(RootComponent);

	Arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	Arm->SetupAttachment(BodyMesh);
	Arm->bInheritPitch = false;
	Arm->bInheritRoll = false;
	Arm->bInheritYaw = false;
	Arm->TargetArmLength = 800;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(Arm);
}

// Called when the game starts or when spawned

void ATank::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void ATank::Shoot()
{
}

void ATank::MoveForward(float Scale)
{
	MoveForwardScale = Scale;
}

void ATank::MoveRight(float Scale)
{
	MoveRightScale = Scale;
}
void ATank::BeginPlay()
{

	Super::BeginPlay();
	
}

void ATank::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Location = GetActorLocation();
	
	auto NewLocation = Location + GetActorForwardVector() * MoveForwardScale * Speed * DeltaTime;
	SetActorLocation(NewLocation, true);

	auto currentLocation = GetActorLocation();
	auto RightVector = GetActorRightVector();
	auto MovePosition = currentLocation + GetActorRightVector() * MoveRightScale * Speed * DeltaTime;
	SetActorLocation(MovePosition, true);

	
	
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
