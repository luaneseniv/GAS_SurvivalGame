// Copyright Lu


#include "Actor/ActorEffect.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"

AActorEffect::AActorEffect()
{
	PrimaryActorTick.bCanEverTick = false;
}

/* Better to call this method in Blueprint */
void AActorEffect::ApplyEffectToTarget(AActor* TargetActor, const TSubclassOf<UGameplayEffect> GEClass)
{
	if (TargetActor == nullptr) return;
	checkf(GEClass, TEXT("Gameplay Effect Class is not set on actor "), *GetActorLabel());

	// Get AbilitySystemInterface
	TScriptInterface<IAbilitySystemInterface> TargetAbilitySystemInterface = TScriptInterface<IAbilitySystemInterface>(TargetActor);
	if (TargetAbilitySystemInterface == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target Actor (%s) is not implemented AbilitySystemInterface!"), *GetActorLabel())
		return;
	}

	UAbilitySystemComponent* AbilitySystemComponent = TargetAbilitySystemInterface->GetAbilitySystemComponent();
	// Create new effect context
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	// Make new effect spec from effect context
	const FGameplayEffectSpecHandle EffectSpec = AbilitySystemComponent->MakeOutgoingSpec(GEClass, 1.0f, EffectContext);
	// Apply the effect to TargetAbilitySystemComponent
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpec.Data.Get());

	Destroy();
}



