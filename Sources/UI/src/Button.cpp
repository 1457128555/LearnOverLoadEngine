#include "Button.h"
#include "Converter.h"

#include <ImGui/imgui_internal.h>

namespace UI
{
	Button::Button(const std::string& p_label, const glm::vec2& p_size, bool p_disabled)
		:mLabel(p_label), mSize(p_size), mDisabled(p_disabled)
	{
		auto& style = ImGui::GetStyle();

		mIdleBackgroundColor	= UI::Converter::ToColor(style.Colors[ImGuiCol_Button]);
		mHoveredBackgroundColor	= UI::Converter::ToColor(style.Colors[ImGuiCol_ButtonHovered]);
		mClickedBackgroundColor	= UI::Converter::ToColor(style.Colors[ImGuiCol_ButtonActive]);
		mTextColor				= UI::Converter::ToColor(style.Colors[ImGuiCol_Text]);
	}

	void Button::_DrawImpl()
	{
		auto& style = ImGui::GetStyle();

		auto defaultIdleColor		= style.Colors[ImGuiCol_Button];
		auto defaultHoveredColor	= style.Colors[ImGuiCol_ButtonHovered];
		auto defaultClickedColor	= style.Colors[ImGuiCol_ButtonActive];
		auto defaultTextColor		= style.Colors[ImGuiCol_Text];

		style.Colors[ImGuiCol_Button]			= UI::Converter::ToImVec4(mIdleBackgroundColor);
		style.Colors[ImGuiCol_ButtonHovered]	= UI::Converter::ToImVec4(mHoveredBackgroundColor);
		style.Colors[ImGuiCol_ButtonActive]		= UI::Converter::ToImVec4(mClickedBackgroundColor);
		style.Colors[ImGuiCol_Text]				= UI::Converter::ToImVec4(mTextColor);

		if (ImGui::ButtonEx((mLabel + mWidgetID).c_str(), UI::Converter::ToImVec2(mSize), mDisabled ? ImGuiButtonFlags_Disabled : 0))
			ClickedEvent.invoke();

		style.Colors[ImGuiCol_Button]			= defaultIdleColor;
		style.Colors[ImGuiCol_ButtonHovered]	= defaultHoveredColor;
		style.Colors[ImGuiCol_ButtonActive]		= defaultClickedColor;
		style.Colors[ImGuiCol_Text]				= defaultTextColor;
	}
}