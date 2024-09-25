// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlyrLoc.generated.h"

/**
 *
 */
UCLASS()
class SHOOTERASSETPACK_API UBTService_PlyrLoc : public UBTService_BlackboardBase
{
	GENERATED_BODY()


public:
	UBTService_PlyrLoc();
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
