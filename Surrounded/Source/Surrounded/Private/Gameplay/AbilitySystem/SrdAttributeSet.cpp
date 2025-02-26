// Copyright Lu


#include "Gameplay/AbilitySystem/SrdAttributeSet.h"
#include "Net/UnrealNetwork.h"

USrdAttributeSet::USrdAttributeSet()
{
	InitHealth(100.0f);
	InitMaxHealth(100.0f);
	InitMana(100.0f);
	InitMaxMana(100.0f);
}

void USrdAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(USrdAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USrdAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USrdAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USrdAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void USrdAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USrdAttributeSet, Health, OldHealth);
}

void USrdAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USrdAttributeSet, MaxHealth, OldMaxHealth);
}

void USrdAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USrdAttributeSet, Mana, OldMana);
}

void USrdAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USrdAttributeSet, MaxMana, OldMaxMana);
}
