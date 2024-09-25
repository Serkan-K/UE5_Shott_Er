// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlyrLoc.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlyrLoc::UBTService_PlyrLoc()
{
	NodeName = TEXT("Update Plyr Loc");
}

void UBTService_PlyrLoc::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);


	APawn* plyr_Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (plyr_Pawn == nullptr) return;
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),
		plyr_Pawn->GetActorLocation());
}
