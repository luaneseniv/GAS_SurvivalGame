// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "SrdAttributeSet.generated.h"

// will be changed to ATTRIBUTE_ACCESSORS_BASIC in UE5.6
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class SURROUNDED_API USrdAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	USrdAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	// OnRep
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_Exp(const FGameplayAttributeData& OldExp) const;

	UFUNCTION()
	void OnRep_MaxExp(const FGameplayAttributeData& OldMaxExp) const;
	
public:
	// Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Essential Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(USrdAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Essential Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USrdAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Essential Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(USrdAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Essential Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(USrdAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Exp, Category = "Essential Attributes")
	FGameplayAttributeData Exp;
	ATTRIBUTE_ACCESSORS(USrdAttributeSet, Exp);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxExp, Category = "Essential Attributes")
	FGameplayAttributeData MaxExp;
	ATTRIBUTE_ACCESSORS(USrdAttributeSet, MaxExp);
};

