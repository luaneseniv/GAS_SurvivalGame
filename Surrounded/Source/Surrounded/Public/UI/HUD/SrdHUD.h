// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SrdHUD.generated.h"

class UOverlayWidgetController;
struct FWidgetControllerParams;
class USrdUserWidget;
class USrdWidgetController;

UCLASS()
class SURROUNDED_API ASrdHUD : public AHUD
{
	GENERATED_BODY()
public:
	UFUNCTION()
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCP);

	// This function is called in Player Character (SrdCharacter)
	// When pawn is possessed and everything is constructed: PS, PC, ASC, AS
	UFUNCTION()
	void InitOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);


public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USrdUserWidget> OverlayWidget;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<USrdUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<USrdWidgetController> OverlayWidgetControllerClass;
	
};
