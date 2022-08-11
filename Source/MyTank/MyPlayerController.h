// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <MyTank/Tank.h>
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"



/**
 * 
 */
UCLASS()
class TANKPROJECT_API AMyPlayerController final : public APlayerController
{
	GENERATED_BODY()

public:
	virtual	void SetupInputComponent() override;
			
	virtual void OnPossess(APawn* InPawn) override;
private:
	void OnShoot() ;

	void OnMoveForward(float Scale) ;

	ATank*  Tank = nullptr;

	void OnMoveRight(float Scale);
};
