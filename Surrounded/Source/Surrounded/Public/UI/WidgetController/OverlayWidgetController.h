// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SrdWidgetController.h"
#include "OverlayWidgetController.generated.h"

/* Delegate for updating visualization on Game overlay widget when attributes changed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedDelegate, float, NewValue);


struct FOnAttributeChangeData;

/*
 * Handle Game Overlay widget
 */
UCLASS(BlueprintType, Blueprintable)
class SURROUNDED_API UOverlayWidgetController : public USrdWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	// Data update Events
	void HealthChanged(const FOnAttributeChangeData& NewData) const;
	void MaxHealthChanged(const FOnAttributeChangeData& NewData) const;
	void ManaChanged(const FOnAttributeChangeData& NewData) const;
	void MaxManaChanged(const FOnAttributeChangeData& NewData) const;
	void ExpChanged(const FOnAttributeChangeData& NewData) const;
	void MaxExpChanged(const FOnAttributeChangeData& NewData) const;
	

public:
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedDelegate OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedDelegate OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedDelegate OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedDelegate OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedDelegate OnExpChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedDelegate OnMaxExpChanged;
};

