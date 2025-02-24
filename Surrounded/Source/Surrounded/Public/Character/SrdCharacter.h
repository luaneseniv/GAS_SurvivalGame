// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "Character/SrdCharacterBase.h"
#include "SrdCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SURROUNDED_API ASrdCharacter : public ASrdCharacterBase
{
	GENERATED_BODY()

public:
	ASrdCharacter();
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;
	
	
};
