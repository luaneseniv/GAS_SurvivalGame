// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SrdUserWidget.generated.h"


UCLASS()
class SURROUNDED_API USrdUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

protected:
	/* Run once SetWidgetController is called */
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;


};
