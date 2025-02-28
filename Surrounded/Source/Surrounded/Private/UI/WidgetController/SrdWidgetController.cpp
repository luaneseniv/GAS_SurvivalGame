// Copyright Lu


#include "UI/WidgetController/SrdWidgetController.h"

void USrdWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCP)
{
	PlayerController = WCP.PlayerController;
	PlayerState = WCP.PlayerState;
	AbilitySystemComponent = WCP.AbilitySystemComponent;
	AttributeSet = WCP.AttributeSet;
}

void USrdWidgetController::BroadcastInitialValues()
{
	
}

void USrdWidgetController::BindCallbacksToDependencies()
{
	
}
