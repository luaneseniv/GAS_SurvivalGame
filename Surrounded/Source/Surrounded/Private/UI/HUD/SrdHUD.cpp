// Copyright Lu


#include "UI/HUD/SrdHUD.h"
#include <Blueprint/UserWidget.h>
#include "UI/Widget/SrdUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ASrdHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCP)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		// Set necessary params for WidgetController
		OverlayWidgetController->SetWidgetControllerParams(WCP);
		// Bind Update events for Widgets controlled
		OverlayWidgetController->BindCallbacksToDependencies();
		
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void ASrdHUD::InitOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	// Check failed if we forget to add 2 classes in Blueprint.
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class is not set, Please check in BP_SrdHUD"))
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class is not set, Please check in BP_SrdHUD"))

	// Create new Game overlay widget
	OverlayWidget = CreateWidget<USrdUserWidget>(GetWorld(), OverlayWidgetClass);

	// Construct params for UOverlayWidgetController
	const FWidgetControllerParams OverlayControllerParams(PC, PS, ASC, AS);

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(OverlayControllerParams);

	// MUST call SetWidgetController before call BroadcastInitialValues()
	// To make sure that WidgetController has been set in OverlayWidget blueprint
	OverlayWidget->SetWidgetController(WidgetController);

	// Broadcast InitValue(s)
	// from: AttributeSet
	// to: OverlayWidget
	WidgetController->BroadcastInitialValues();

	// Finally, add Game overlay widget to the viewport
	OverlayWidget->AddToViewport();
	
}


