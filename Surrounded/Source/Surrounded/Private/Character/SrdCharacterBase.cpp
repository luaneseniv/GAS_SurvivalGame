// Copyright Lu


#include "Character/SrdCharacterBase.h"


ASrdCharacterBase::ASrdCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName(TEXT("weapon_main")));
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



