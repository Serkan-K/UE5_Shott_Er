// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SHOOTERASSETPACK_API AGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGun();

	void Pull_Trigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root_comp;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* mesh;

	UPROPERTY(EditAnywhere)
	float Max_Range = 1000;

	UPROPERTY(EditAnywhere)
	float Damage_ = 10;






	UPROPERTY(EditAnywhere)
	UParticleSystem* Muzzle_Flash;

	UPROPERTY(EditAnywhere)
	UParticleSystem* Impact_FX;



	UPROPERTY(EditAnywhere)
	USoundBase* muzzle_SFX;
	UPROPERTY(EditAnywhere)
	USoundBase* hit_SFX;






	bool GunTrace(FHitResult& Hit, FVector& Shot_Dir);
	AController* getOwner_ctrlr() const;
};
