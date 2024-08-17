#include "WidgetContainer.h"

#include <algorithm>

namespace UI
{
	void WidgetContainer::removeWidget(AWidget& widget)
	{
		auto findIt = std::find_if(mWidgets.begin(), mWidgets.end(),
			[&widget](std::pair<AWidget*, EMemoryMode>& value) {
				return value.first == &widget;
		});

		if (findIt != mWidgets.end())
		{
			if (findIt->second == EMemoryMode::INTERNAL_MANAGMENT)
				delete findIt->first;
			mWidgets.erase(findIt);
		}
	}

	void WidgetContainer::removeAllWidgets()
	{
		std::for_each(mWidgets.begin(), mWidgets.end(),[](auto& value) {
			if (value.second == EMemoryMode::INTERNAL_MANAGMENT)
				delete value.first;
		});
		mWidgets.clear();
	}

	void WidgetContainer::considerWidget(AWidget& widget, bool manageMemory)
	{
		mWidgets.emplace_back(std::make_pair(&widget, manageMemory ?
			EMemoryMode::INTERNAL_MANAGMENT : EMemoryMode::EXTERNAL_MANAGMENT));
		widget.setParent(this);
	}

	void WidgetContainer::unconsiderWidget(AWidget& widget)
	{
		auto findIt = std::find_if(mWidgets.begin(), mWidgets.end(),
			[&widget](std::pair<AWidget*, EMemoryMode>& value) {
				return value.first == &widget;
		});

		if (findIt != mWidgets.end())
		{
			widget.setParent(nullptr);
			mWidgets.erase(findIt);
		}
	}

	void WidgetContainer::collectGarbages()
	{
		for (auto it = mWidgets.begin(); it != mWidgets.end(); )
		{
			bool toDestory = it->first && it->first->isDestroyed();
			if (toDestory && it->second == EMemoryMode::INTERNAL_MANAGMENT)
				delete it->first;

			if (toDestory)
				mWidgets.erase(it);
			else
				it++;
		}
	}

	void WidgetContainer::drawWidgets()
	{
		collectGarbages();

		if (mReversedDrawOrder)
		{
			for (auto it = mWidgets.crbegin(); it != mWidgets.crend(); it++)
				it->first->draw();
		}
		else
		{
			for (const auto& widget : mWidgets)
				widget.first->draw();
		}
	}
}