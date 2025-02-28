// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SrdWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, Health);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, Mana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, MaxMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExpChangedSignature, float, Exp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxExpChangedSignature, float, MaxExp);


UCLASS(BlueprintType, Blueprintable)
class SURROUNDED_API UOverlayWidgetController : public USrdWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	// Data updates Events
	void HealthChanged(const FOnAttributeChangeData& NewData) const;
	void MaxHealthChanged(const FOnAttributeChangeData& NewData) const;
	void ManaChanged(const FOnAttributeChangeData& NewData) const;
	void MaxManaChanged(const FOnAttributeChangeData& NewData) const;
	void ExpChanged(const FOnAttributeChangeData& NewData) const;
	void MaxExpChanged(const FOnAttributeChangeData& NewData) const;
	

public:
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnExpChangedSignature OnExpChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxExpChangedSignature OnMaxExpChanged;
};

