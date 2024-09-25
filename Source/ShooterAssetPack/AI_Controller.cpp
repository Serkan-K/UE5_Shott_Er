// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "My_Character.h"



void AAI_Controller::BeginPlay()
{
	Super::BeginPlay();

	if (AI_Behavior != nullptr)
	{
		RunBehaviorTree(AI_Behavior);

		APawn* plyr_Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"),
			plyr_Pawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("Start_Pos"),
			GetPawn()->GetActorLocation());
	}
}


void AAI_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//APawn* plyr_Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


	//if (LineOfSightTo(plyr_Pawn))
	//{
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"),
	//		plyr_Pawn->GetActorLocation());
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("Last_Pos"),
	//		plyr_Pawn->GetActorLocation());
	//}
	//else
	//{
	//	GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//}



	//if (LineOfSightTo(plyr_Pawn))
	//{
	//	SetFocus(plyr_Pawn);
	//	MoveToActor(plyr_Pawn, chase_Range);
	//}
	//else
	//{
	//	ClearFocus(EAIFocusPriority::Gameplay);
	//	StopMovement();
	//}
}

bool AAI_Controller::IsDead() const
{
	AMy_Character* ctrled_Char = Cast< AMy_Character>(GetPawn());
	if (ctrled_Char != nullptr)
	{
		return ctrled_Char->IsDead();
	}
	return true;
}
