#pragma once

#include <glm/glm.hpp>
#include <ImGui/imgui.h>

namespace UI
{
	class Converter
	{
	public:
		static ImVec2 ToImVec2(const glm::vec2& v) 
		{
			return ImVec2(v.x, v.y);
		}

		static glm::vec2 ToFVector2(const ImVec2& v)
		{
			return { v.x, v.y };
		}

		static ImVec4 ToImVec4(const glm::vec4& v)
		{
			return ImVec4(v.x, v.y, v.z, v.w);
		}

		static glm::vec4 ToColor(const ImVec4& v)
		{
			return { v.x, v.y, v.z, v.w };
		}	
	};
}