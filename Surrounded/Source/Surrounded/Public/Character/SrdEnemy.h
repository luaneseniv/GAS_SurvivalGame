// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "Character/SrdCharacterBase.h"
#include "Gameplay/Interface/InteractInterface.h"
#include "SrdEnemy.generated.h"


UCLASS()
class SURROUNDED_API ASrdEnemy : public ASrdCharacterBase, public IInteractInterface
{
	GENERATED_BODY()

public:
	ASrdEnemy();
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void I_HighlightActor() override;
	
	UFUNCTION()
	virtual void I_UnHighlightActor() override;

	
	
};
