// Copyright Lu


#include "Character/SrdCharacterBase.h"


ASrdCharacterBase::ASrdCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), "weapon_main");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

UAbilitySystemComponent* ASrdCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASrdCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	
}



