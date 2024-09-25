// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_Shoot.h"
#include "AIController.h"
#include "My_Character.h"


UBTTaskNode_Shoot::UBTTaskNode_Shoot()
{
	NodeName = TEXT("Shooter");
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AMy_Character* chrcter = Cast<AMy_Character>(OwnerComp.GetAIOwner()->GetPawn());
	if (chrcter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	chrcter->Shoot();
	return EBTNodeResult::Succeeded;
}