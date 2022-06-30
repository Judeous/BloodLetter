#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenu.generated.h"

UCLASS()
class BLOODLETTER_API AMainMenu : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

protected:

	TSharedPtr<class SMainMenu> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;

};
