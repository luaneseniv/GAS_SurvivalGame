// Copyright Lu


#include "Character/SrdCharacterBase.h"


ASrdCharacterBase::ASrdCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), WeaponSocket);
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

void ASrdCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	
}



