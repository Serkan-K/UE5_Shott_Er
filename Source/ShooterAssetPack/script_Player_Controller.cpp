// Fill out your copyright notice in the Description page of Project Settings.


#include "script_Player_Controller.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void Ascript_Player_Controller::BeginPlay()
{
	Super::BeginPlay();

	hud_ = CreateWidget(this, HUD_UI);
	if (hud_ != nullptr)
	{
		hud_->AddToViewport();
	}

}

void Ascript_Player_Controller::GameHasEnded(AActor* EndGameFocus, bool IsWin)
{
	Super::GameHasEnded(EndGameFocus, IsWin);


	hud_->RemoveFromViewport();

	if (IsWin)
	{
		UUserWidget* win_Screen = CreateWidget(this, Win_UI);
		if (win_Screen != nullptr)
		{
			win_Screen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* lose_Screen = CreateWidget(this, lose_UI);
		if (lose_Screen != nullptr)
		{
			lose_Screen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(restart_Timer, this, &APlayerController::RestartLevel, restart_Delay);
}
