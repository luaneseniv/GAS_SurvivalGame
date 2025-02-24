// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "Character/SrdCharacterBase.h"
#include "AbilitySystemInterface.h"
#include "SrdCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SURROUNDED_API ASrdCharacter : public ASrdCharacterBase
{
	GENERATED_BODY()

public:
	ASrdCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
protected:
	virtual void BeginPlay() override;

private:
	void InitAbilityActorInfo();
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;
	
	
};



