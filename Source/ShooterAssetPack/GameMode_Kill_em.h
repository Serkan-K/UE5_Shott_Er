// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode_Shoot_Er.h"
#include "GameMode_Kill_em.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API AGameMode_Kill_em : public AGameMode_Shoot_Er
{
	GENERATED_BODY()
	

public:
	virtual void Pawn_Killed(APawn* PawnKilled) override;

private:
	void EndGame(bool PlayerWin);
};
