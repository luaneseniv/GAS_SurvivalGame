// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS(Abstract)
class SURROUNDED_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;


public:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	/*
	 * Attach the weapon to this socket name on character's skeletal mesh.
	 */ 
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	FName SocketName = "weapon_main";

	

};
