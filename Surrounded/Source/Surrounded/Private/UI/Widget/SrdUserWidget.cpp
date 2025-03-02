// Copyright Lu


#include "UI/Widget/SrdUserWidget.h"

void USrdUserWidget::SetWidgetController(UObject* InWidgetController)
{
	// Assign widget controller for this widget.
	WidgetController = InWidgetController;
	// After assign widget controller for this widget
	// call this Blueprint Implementable Event
	// This is used for binding custom events inside blueprint.
	WidgetControllerSet();
}

