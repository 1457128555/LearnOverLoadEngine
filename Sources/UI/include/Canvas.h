#pragma once

#include "IDrawable.h"

#include <vector>

namespace UI
{
	class APanel;

	class Canvas : public IDrawable
	{
	public:
		void addPanel(APanel* panel);

		void removePanel(APanel* panel);

		void removeAllPanels();

		void makeDockSpace(bool state);

		bool isDockSpace()const;

		void draw() override;

	private:
		bool mIsDock = false;
		std::vector<APanel*> mPanels;
	};
}

