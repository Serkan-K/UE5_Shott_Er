// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Controller.generated.h"

/**
 *
 */
UCLASS()
class SHOOTERASSETPACK_API AAI_Controller : public AAIController
{
	GENERATED_BODY()


public:
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;




private:
	//UPROPERTY(EditAnywhere)
	//float chase_Range = 200;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AI_Behavior;

};
