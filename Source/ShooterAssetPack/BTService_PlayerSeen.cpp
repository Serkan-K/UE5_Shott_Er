// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerSeen.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTService_PlayerSeen::UBTService_PlayerSeen()
{
	NodeName = TEXT("Update PlyrLoc Seen");
}

void UBTService_PlayerSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);


	APawn* plyr_Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (plyr_Pawn == nullptr) return;

	if (OwnerComp.GetAIOwner() == nullptr) return;


	if (OwnerComp.GetAIOwner()->LineOfSightTo(plyr_Pawn))
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), plyr_Pawn);
	else
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
}


