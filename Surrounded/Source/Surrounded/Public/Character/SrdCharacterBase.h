// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SrdCharacterBase.generated.h"

UCLASS(Abstract)
class SURROUNDED_API ASrdCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASrdCharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	/*
	 * Attach the weapon to this socket name on character's skeletal mesh.
	 */ 
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	FName WeaponSocket = "weapon_main";

	

};
