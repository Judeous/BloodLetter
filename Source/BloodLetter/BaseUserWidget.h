#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"

#include "BaseUserWidget.generated.h"

UCLASS()
class BLOODLETTER_API UBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UBaseUserWidget(const FObjectInitializer& objectInitializer);
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;


	/*
public:

private:
	*/
};
