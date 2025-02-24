// Copyright Lu


#include "Character/SrdEnemy.h"
#include "Surrounded/Surrounded.h"
#include "Gameplay/AbilitySystem/SrdAbilitySystemComponent.h"
#include "Gameplay/AbilitySystem/SrdAttributeSet.h"

ASrdEnemy::ASrdEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	// Set Default to block visibility channel
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilitySystemComponent = CreateDefaultSubobject<USrdAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<USrdAttributeSet>(TEXT("AttributeSet"));
	
	
}

void ASrdEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	AbilitySystemComponent->InitAbilityActorInfo(this, this);

}

// ~ Interfaces
void ASrdEnemy::I_HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void ASrdEnemy::I_UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
// ~ End Interfaces
