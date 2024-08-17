#pragma once

#include "AWidget.h"
#include "Event.h"

#include <glm/glm.hpp>

namespace UI
{
	class AButton : public AWidget
	{
	protected:
		void _DrawImpl()override = 0;
	public:
		Tool::Event<> ClickedEvent;
	};

	class Button : public AButton
	{
	public:
		Button(const std::string& p_label = "", const glm::vec2& p_size = glm::vec2(0.f), bool p_disabled = false);

	protected:
		void _DrawImpl()override;

	public:
		std::string mLabel;
		glm::vec2 mSize;
		bool mDisabled = false;

		glm::vec4 mIdleBackgroundColor;
		glm::vec4 mHoveredBackgroundColor;
		glm::vec4 mClickedBackgroundColor;

		glm::vec4 mTextColor;
	};
}