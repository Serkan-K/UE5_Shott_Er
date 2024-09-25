// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root_comp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root_comp);

	mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(Root_comp);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}








bool AGun::GunTrace(FHitResult& Hit, FVector& Shot_Dir)
{
	AController* Owner_Controller = getOwner_ctrlr();
	if (Owner_Controller == nullptr)
		return false;




	FVector loc; FRotator rot;
	Owner_Controller->GetPlayerViewPoint(loc, rot);
	Shot_Dir = -rot.Vector();

	FVector end_Point = loc + rot.Vector() * Max_Range;




	FCollisionQueryParams params_;
	params_.AddIgnoredActor(this);
	params_.AddIgnoredActor(GetOwner());





	return GetWorld()->LineTraceSingleByChannel(Hit, loc, end_Point, ECollisionChannel::ECC_GameTraceChannel1, params_);

}






AController* AGun::getOwner_ctrlr() const
{
	APawn* Owner_Pawn = Cast<APawn>(GetOwner());
	if (Owner_Pawn == nullptr)
		return nullptr;
	return Owner_Pawn->GetController();
}
















void AGun::Pull_Trigger()
{
	UGameplayStatics::SpawnEmitterAttached(Muzzle_Flash, mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(muzzle_SFX, mesh, TEXT("MuzzleFlashSocket"));


	FHitResult hit_;
	FVector shot_Dir;

	bool IsHit = GunTrace(hit_, shot_Dir);

	if (IsHit)
	{
		/*DrawDebugPoint(GetWorld(), hit_.Location, 10, FColor::Red, false, 1);*/

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Impact_FX, hit_.Location, shot_Dir.Rotation(), true);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), hit_SFX, hit_.Location);

		AActor* hit_Actor = hit_.GetActor();
		if (hit_Actor != nullptr)
		{
			FPointDamageEvent Damage_Event(Damage_, hit_, shot_Dir, nullptr);

			AController* Owner_Controller = getOwner_ctrlr();
			hit_Actor->TakeDamage(Damage_, Damage_Event, Owner_Controller, this);
		}
	}

}