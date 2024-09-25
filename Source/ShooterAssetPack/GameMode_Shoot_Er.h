// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_Shoot_Er.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API AGameMode_Shoot_Er : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void Pawn_Killed(APawn* PawnKilled);
	
};
