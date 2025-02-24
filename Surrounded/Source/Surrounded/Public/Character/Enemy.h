// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Gameplay/Interface/InteractInterface.h"
#include "Enemy.generated.h"


UCLASS()
class SURROUNDED_API AEnemy : public ACharacterBase, public IInteractInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void I_HighlightActor() override;
	
	UFUNCTION()
	virtual void I_UnHighlightActor() override;

	
	
};
