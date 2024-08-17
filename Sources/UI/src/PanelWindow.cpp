#include "PanelWindow.h"
#include "Converter.h"

#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>

namespace UI
{
	PanelWindow::PanelWindow(const std::string& name, bool opened, const PanelWindowSettings set)
		:mName(name), mOpened(opened), mSet(set)
	{
		mAutoSize = set.autoSize;
	}

	void PanelWindow::open()
	{
		if (!mOpened)
		{
			mOpened = true;
			//	OpenEvent.Invoke();
		}
	}

	void PanelWindow::close()
	{
		if (mOpened)
		{
			mOpened = false;
			//	CloseEvent.Invoke();
		}
	}

	void PanelWindow::focus()
	{
		ImGui::SetWindowFocus((mName + mPanelID).c_str());
	}

	void PanelWindow::scrollToBottom()
	{
		mMustScrollToBottom = true;
	}

	void PanelWindow::scrollToTop()
	{
		mMustScrollToTop = true;
	}

	void PanelWindow::setOpened(bool p_value)
	{
		if (p_value != mOpened)
			p_value == true ? open() : close();
	}

	bool PanelWindow::isOpened() const
	{
		return mOpened;
	}

	bool PanelWindow::isHovered() const
	{
		return mHovered;
	}

	bool PanelWindow::isFocused() const
	{
		return mFocused;
	}

	bool PanelWindow::isAppearing() const
	{
		auto window = ImGui::FindWindowByName((mName + getPanelID()).c_str());
		if (window)
			return window->Appearing;
		else
			return false;
	}

	bool PanelWindow::isScrolledToBottom() const
	{
		return mScrolledToBottom;
	}

	bool PanelWindow::isScrolledToTop() const
	{
		return mScrolledToTop;
	}

	void PanelWindow::_DrawImpl()
	{
		if (mOpened)
		{
			int windowFlags = ImGuiWindowFlags_None;

			if (!mSet.resizable)				windowFlags |= ImGuiWindowFlags_NoResize;
			if (!mSet.movable)					windowFlags |= ImGuiWindowFlags_NoMove;
			if (!mSet.dockable)					windowFlags |= ImGuiWindowFlags_NoDocking;
			if (mSet.hideBackground)			windowFlags |= ImGuiWindowFlags_NoBackground;
			if (mSet.forceHorizontalScrollbar)	windowFlags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
			if (mSet.forceVerticalScrollbar)	windowFlags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
			if (mSet.allowHorizontalScrollbar)	windowFlags |= ImGuiWindowFlags_HorizontalScrollbar;
			if (!mSet.bringToFrontOnFocus)		windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
			if (!mSet.collapsable)				windowFlags |= ImGuiWindowFlags_NoCollapse;
			if (!mSet.allowInputs)				windowFlags |= ImGuiWindowFlags_NoInputs;
			if (!mSet.scrollable)				windowFlags |= ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar;
			if (!mSet.titleBar)					windowFlags |= ImGuiWindowFlags_NoTitleBar;

			ImVec2 minSizeConstraint = Converter::ToImVec2(mMinSize);
			ImVec2 maxSizeConstraint = Converter::ToImVec2(mMaxSize);

			/* Cancel constraint if x or y is <= 0.f */
			if (minSizeConstraint.x <= 0.f || minSizeConstraint.y <= 0.f)
				minSizeConstraint = { 0.0f, 0.0f };

			if (maxSizeConstraint.x <= 0.f || maxSizeConstraint.y <= 0.f)
				maxSizeConstraint = { 10000.f, 10000.f };

			ImGui::SetNextWindowSizeConstraints(minSizeConstraint, maxSizeConstraint);

			if (ImGui::Begin((mName + mPanelID).c_str(), mSet.closable ? &mOpened : nullptr, windowFlags))
			{
				mHovered = ImGui::IsWindowHovered();
				mFocused = ImGui::IsWindowFocused();

				auto scrollY = ImGui::GetScrollY();

				mScrolledToBottom = scrollY == ImGui::GetScrollMaxY();
				mScrolledToTop = scrollY == 0.0f;

			//	if (!mOpened)
			//		CloseEvent.Invoke();

				update();

				if (mMustScrollToBottom)
				{
					ImGui::SetScrollY(ImGui::GetScrollMaxY());
					mMustScrollToBottom = false;
				}

				if (mMustScrollToTop)
				{
					ImGui::SetScrollY(0.0f);
					mMustScrollToTop = false;
				}

				drawWidgets();
			}

			ImGui::End();
		}
	}
}