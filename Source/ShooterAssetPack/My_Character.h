// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "My_Character.generated.h"


class AGun;

UCLASS()
class SHOOTERASSETPACK_API AMy_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMy_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;


	UFUNCTION(BlueprintPure) bool IsDead() const;
	UFUNCTION(BlueprintPure) float health_() const;

	void Shoot();


private:
	void Move_X(float Axis_Value);
	void Move_Y(float Axis_Value);

	void Look_GamePad_Y(float Axis_Value);
	void Look_GamePad_X(float Axis_Value);




	UPROPERTY(EditAnywhere)	float Rotation_Rate;

	UPROPERTY(EditDefaultsOnly)	TSubclassOf<AGun> Gun_Class;

	UPROPERTY()	AGun* Gun_;



	UPROPERTY(EditAnywhere)	float Max_Health;
	UPROPERTY(VisibleAnywhere)	float Health_Curr;
};
