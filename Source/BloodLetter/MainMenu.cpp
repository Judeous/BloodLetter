#include "MainMenu.h"

#include "SMainMenu.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AMainMenu::BeginPlay()
{
	Super::BeginPlay();

	ShowMenu();
}

void AMainMenu::ShowMenu()
{
	if (bMenuIsMade && MenuWidget.IsValid())
	{
		MenuWidget.Get()->SetVisibility(EVisibility::Visible);
		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
		return;
	}

	if (GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SMainMenu).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
		bMenuIsMade = true;
	}
}
void AMainMenu::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		MenuWidget.Get()->SetVisibility(EVisibility::Hidden);

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}