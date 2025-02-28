// Copyright Lu


#include "UI/WidgetController/OverlayWidgetController.h"

#include "Gameplay/AbilitySystem/SrdAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	USrdAttributeSet* SrdAttributes = CastChecked<USrdAttributeSet>(AttributeSet);
	// Health
	OnHealthChanged.Broadcast(SrdAttributes->GetHealth());
	OnMaxHealthChanged.Broadcast(SrdAttributes->GetMaxHealth());
	// Mana
	OnManaChanged.Broadcast(SrdAttributes->GetMana());
	OnMaxManaChanged.Broadcast(SrdAttributes->GetMaxMana());
	// Exp
	OnExpChanged.Broadcast(SrdAttributes->GetExp());
	OnMaxExpChanged.Broadcast(SrdAttributes->GetMaxExp());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	USrdAttributeSet* SrdAttributes = CastChecked<USrdAttributeSet>(AttributeSet);

	// Health updated
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SrdAttributes->GetHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::HealthChanged);
	// Max Health updated
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SrdAttributes->GetMaxHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	
	// Mana updated
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SrdAttributes->GetManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::ManaChanged);
	// Max Mana updated
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SrdAttributes->GetMaxManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	
	// Exp updated
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SrdAttributes->GetExpAttribute())
		.AddUObject(this, &UOverlayWidgetController::ExpChanged);
	// Max Exp updated
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SrdAttributes->GetMaxExpAttribute())
		.AddUObject(this, &UOverlayWidgetController::MaxExpChanged);
	
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& NewData) const
{
	OnHealthChanged.Broadcast(NewData.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& NewData) const
{
	OnMaxHealthChanged.Broadcast(NewData.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& NewData) const
{
	OnManaChanged.Broadcast(NewData.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& NewData) const
{
	OnMaxManaChanged.Broadcast(NewData.NewValue);
}

void UOverlayWidgetController::ExpChanged(const FOnAttributeChangeData& NewData) const
{
	OnExpChanged.Broadcast(NewData.NewValue);
}

void UOverlayWidgetController::MaxExpChanged(const FOnAttributeChangeData& NewData) const
{
	OnMaxExpChanged.Broadcast(NewData.NewValue);
}
