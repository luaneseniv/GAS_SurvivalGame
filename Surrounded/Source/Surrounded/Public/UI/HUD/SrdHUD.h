// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SrdHUD.generated.h"

class UOverlayWidgetController;
struct FWidgetControllerParams;
class USrdUserWidget;
class USrdWidgetController;

class UAbilitySystemComponent;
class UAttributeSet;

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
	/*
	 * Class of GameOverlay widget.
	 * Showing Player's stats (e.g: mana, health, exp,...)
	 */
	UPROPERTY(EditAnywhere)
	TSubclassOf<USrdUserWidget> OverlayWidgetClass;

	// Handle data syncing from Ability System to UI Overlay
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	/*
	 * Class of widget Handler
	 * Transfer data from AbilitySystem to Player's stat widget
	 */
	UPROPERTY(EditAnywhere)
	TSubclassOf<USrdWidgetController> OverlayWidgetControllerClass;
	
};
