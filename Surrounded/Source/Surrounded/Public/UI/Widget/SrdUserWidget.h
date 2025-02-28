// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SrdUserWidget.generated.h"

class SrdWidgetController;

UCLASS()
class SURROUNDED_API USrdUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
