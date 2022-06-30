#pragma once

#include "CoreMinimal.h"
#include "BaseUserWidget.h"
#include "PlayerHUD.generated.h"

UCLASS()
class BLOODLETTER_API UPlayerHUD : public UBaseUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* HealthBar;
};
