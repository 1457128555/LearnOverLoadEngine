#pragma once

#include "APanelTransformable.h"
#include "PanelWindowSettings.h"

namespace UI
{
	class PanelWindow : public APanelTransformable
	{
	public:
		PanelWindow(const std::string& name = "", bool opened = true,
			const PanelWindowSettings set = PanelWindowSettings());

		void open();
		void close();
		void focus();

		void scrollToBottom();
		void scrollToTop();

		void setOpened(bool p_value);

		bool isOpened()				const;
		bool isHovered()			const;
		bool isFocused()			const;
		bool isAppearing()			const;
		bool isScrolledToBottom()	const;
		bool isScrolledToTop()		const;

	protected:
		virtual void _DrawImpl() override;

	public:
		std::string mName;
		glm::vec2 mMinSize = glm::vec2(0.f);
		glm::vec2 mMaxSize = glm::vec2(0.f);

		PanelWindowSettings mSet;
	private:
		bool mOpened = false;
		bool mHovered = false;
		bool mFocused = false;
		bool mMustScrollToBottom = false;
		bool mMustScrollToTop = false;
		bool mScrolledToBottom = false;
		bool mScrolledToTop = false;
	};
}

