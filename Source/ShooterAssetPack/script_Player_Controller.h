// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "script_Player_Controller.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API Ascript_Player_Controller : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;


public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool IsWin = false) override;

private:
	UPROPERTY(EditAnywhere)	float restart_Delay = 3;

	FTimerHandle restart_Timer;


	UPROPERTY(EditAnywhere)	TSubclassOf<class UUserWidget> HUD_UI;
	UPROPERTY(EditAnywhere)	TSubclassOf<class UUserWidget> Win_UI;
	UPROPERTY(EditAnywhere)	TSubclassOf<class UUserWidget> lose_UI;

	UPROPERTY(EditAnywhere)	UUserWidget* hud_;
};
