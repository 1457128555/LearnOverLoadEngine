#include "AWidget.h"

#include <ImGui/imgui.h>

namespace UI
{
	AWidget::AWidget()
	{
		mWidgetID = "##" + std::to_string(__WIDGET_ID_INCREMENT++);
	}

	void AWidget::draw()
	{
		if (mEnabled)
		{
			_DrawImpl();

			if (mAutoExecutePlugins)	executePlugins();
			if (!mLinkBreak)			ImGui::SameLine();
		}
	}
}