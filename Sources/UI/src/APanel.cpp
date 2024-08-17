#include "APanel.h"

namespace UI
{
	APanel::APanel()
	{
		mPanelID = "##" + std::to_string(__PANEL_ID_INCREMENT++);
	}

	void APanel::draw()
	{
		if (mEnabled)
			_DrawImpl();
	}
}