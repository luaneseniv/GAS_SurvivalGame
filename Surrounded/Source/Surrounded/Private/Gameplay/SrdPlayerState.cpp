// Copyright Lu


#include "Gameplay/SrdPlayerState.h"

#include "Gameplay/AbilitySystem/SrdAbilitySystemComponent.h"
#include "Gameplay/AbilitySystem/SrdAttributeSet.h"

ASrdPlayerState::ASrdPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USrdAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USrdAttributeSet>(TEXT("AttributeSet"));
	
	NetUpdateFrequency = 100.0f;
}


UAbilitySystemComponent* ASrdPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}





