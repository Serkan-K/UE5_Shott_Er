// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboard_Value.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboard_Value::UBTTask_ClearBlackboard_Value()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboard_Value::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}
