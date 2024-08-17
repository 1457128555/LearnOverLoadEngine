#pragma once

#include "AWidget.h"
#include "EMemoryMode.h"

namespace UI
{
	//	The base class for any widget container
	class WidgetContainer
	{
	public:
		WidgetContainer() = default;
		virtual ~WidgetContainer() { removeAllWidgets(); };

		void removeWidget(AWidget& widget);

		void removeAllWidgets();

		void considerWidget(AWidget& widget, bool manageMemory = true);

		void unconsiderWidget(AWidget& widget);

		void collectGarbages();

		void drawWidgets();

		void reverseDrawOrder(bool reversed = true) { mReversedDrawOrder = reversed; };

		template<typename T, typename ... Args>
		T& createWidget(Args&&... args)
		{
			mWidgets.emplace_back(new T(args...), EMemoryMode::INTERNAL_MANAGMENT);
			T& instance = *(T*)(mWidgets.back().first);
			instance.setParent(this);
			return instance;
		}

		std::vector<std::pair<AWidget*, EMemoryMode>>& getWidgets() { return mWidgets; };
	protected:
		bool mReversedDrawOrder = false;
		std::vector<std::pair<AWidget*, EMemoryMode>> mWidgets;
	};
}