#include "MainMenu.h"

#include "SMainMenu.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AMainMenu::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SMainMenu).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
	}
}