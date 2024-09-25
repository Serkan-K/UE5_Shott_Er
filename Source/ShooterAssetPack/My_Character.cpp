// Fill out your copyright notice in the Description page of Project Settings.


#include "My_Character.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "GameMode_Shoot_Er.h"


AMy_Character::AMy_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void AMy_Character::BeginPlay()
{
	Super::BeginPlay();


	Health_Curr = Max_Health;




	Gun_ = GetWorld()->SpawnActor<AGun>(Gun_Class);

	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);

	Gun_->AttachToComponent(GetMesh(),
		FAttachmentTransformRules::KeepRelativeTransform, TEXT("Weapon_Socket"));

	Gun_->SetOwner(this);
}


void AMy_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}











void AMy_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveY"), this, &AMy_Character::Move_Y);
	PlayerInputComponent->BindAxis(TEXT("MoveX"), this, &AMy_Character::Move_X);
	PlayerInputComponent->BindAxis(TEXT("Look_Vertic"), this, &AMy_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("Look_Horizon"), this, &AMy_Character::AddControllerYawInput);

	PlayerInputComponent->BindAxis(TEXT("Look_GamePad_Y"), this, &AMy_Character::Look_GamePad_Y);
	PlayerInputComponent->BindAxis(TEXT("Look_GamePad_X"), this, &AMy_Character::Look_GamePad_X);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AMy_Character::Shoot);

}






void AMy_Character::Move_Y(float Axis_Value)
{
	AddMovementInput(GetActorForwardVector() * Axis_Value);
}

void AMy_Character::Move_X(float Axis_Value)
{
	AddMovementInput(GetActorRightVector() * Axis_Value);
}

void AMy_Character::Look_GamePad_Y(float Axis_Value)
{
	AddControllerPitchInput(Axis_Value * Rotation_Rate * GetWorld()->GetDeltaSeconds());
}

void AMy_Character::Look_GamePad_X(float Axis_Value)
{
	AddControllerYawInput(Axis_Value * Rotation_Rate * GetWorld()->GetDeltaSeconds());
}


void AMy_Character::Shoot()
{
	Gun_->Pull_Trigger();
}



bool AMy_Character::IsDead() const
{
	return Health_Curr <= 0;
}

float AMy_Character::health_() const
{
	return Health_Curr/ Max_Health;
}




float AMy_Character::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	float Dmg_toApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	Dmg_toApply = FMath::Min(Health_Curr, Dmg_toApply);
	Health_Curr -= Dmg_toApply;

	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health_Curr);



	if (IsDead())
	{
		AGameMode_Shoot_Er* game_Mode = GetWorld()->GetAuthGameMode<AGameMode_Shoot_Er>();
		if (game_Mode != nullptr)
		{
			game_Mode->Pawn_Killed(this);
		}

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}






	return Dmg_toApply;
}






