#pragma once

#include <WidgetContainer.h>

#include <unordered_map>
#include <vector>

namespace UI
{
	class APanel : public IDrawable, public WidgetContainer
	{
	public:
		APanel();

		void draw() override;

		const std::string& getPanelID()const { return mPanelID; };

	protected:
		virtual void _DrawImpl() = 0;

	public:
		bool mEnabled = true;

	protected:
		std::string mPanelID;

	private:
		inline static uint64_t __PANEL_ID_INCREMENT = 0;
	};
}

