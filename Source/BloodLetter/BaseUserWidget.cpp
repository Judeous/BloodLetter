#include "BaseUserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

UBaseUserWidget::UBaseUserWidget(const FObjectInitializer& objectInitializer) :Super(objectInitializer)
{
}

void UBaseUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UBaseUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{

}