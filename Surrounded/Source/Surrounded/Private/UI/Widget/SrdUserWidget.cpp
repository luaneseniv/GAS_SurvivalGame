// Copyright Lu


#include "UI/Widget/SrdUserWidget.h"

void USrdUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}

