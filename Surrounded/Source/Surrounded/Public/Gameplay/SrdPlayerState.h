// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SrdPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class SURROUNDED_API ASrdPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASrdPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}

	
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
	


	
	
};
