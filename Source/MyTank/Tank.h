// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Runtime/Engine/Classes/GameFramework/SpringArmComponent.h>
#include "CoreMinimal.h"
#include <Runtime/Engine/Classes/Camera/CameraComponent.h>
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"




UCLASS()
class TANKPROJECT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	UBoxComponent* Collision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	UStaticMeshComponent* BodyMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	USpringArmComponent* Arm;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	UCameraComponent* Camera;
	

	// Sets default values for this pawn's properties
	ATank();
	virtual void OnConstruction(const FTransform& Transform) override;
	
	void Shoot();
	void MoveForward(float Scale);
	void MoveRight(float Scale);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=MovementParams)
	float Speed = 500;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float MoveForwardScale = 0;
	float MoveRightScale = 0;
	
	

};
