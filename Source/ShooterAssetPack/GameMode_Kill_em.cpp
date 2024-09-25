// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_Kill_em.h"
#include "EngineUtils.h"
#include "AI_Controller.h"

void AGameMode_Kill_em::Pawn_Killed(APawn* PawnKilled)
{
	Super::Pawn_Killed(PawnKilled);

	APlayerController* plyr_Ctrl = Cast< APlayerController>(PawnKilled->GetController());
	if (plyr_Ctrl != nullptr)
	{
		/*plyr_Ctrl->GameHasEnded(nullptr, false);*/
		EndGame(false);
	}
	for (AAI_Controller* ai_ctrl : TActorRange< AAI_Controller>(GetWorld()))
	{
		if (!ai_ctrl->IsDead())
			return;
	}
	EndGame(true);
}

void AGameMode_Kill_em::EndGame(bool Is_PlayerWin)
{
	for (AController* controller : TActorRange<AController>(GetWorld()))
	{
		bool IsPlayerCtrl = controller->IsPlayerController() == Is_PlayerWin;

		controller->GameHasEnded(controller->GetPawn(), Is_PlayerWin);
	}
}
