#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

class SMainMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenu) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenu>, OwningHUD)

	SLATE_END_ARGS()

	/** every widget need a contructor function */
	void Construct(const FArguments& InArgs);

	FReply OnPlayClicked() const;
	FReply OnQuitClicked() const;

	TWeakObjectPtr<class AMainMenu> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};