#include "MainGameMode.h"
#include "MainMenu.h"
#include "PlayerCharacter.h"

AMainGameMode::AMainGameMode()
{
	HUDClass = AMainMenu::StaticClass();
}