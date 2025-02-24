// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SURROUNDED_API IInteractInterface
{
	GENERATED_BODY()

public:
	virtual void I_HighlightActor() = 0;
	virtual void I_UnHighlightActor() = 0;
};
