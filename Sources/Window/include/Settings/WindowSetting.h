#pragma once

#include <string>

namespace Window
{
	struct WindowSettings
	{
		std::string title	=	"Default Title";
		uint32_t	width	=	800u;
		uint32_t	height	=	600u;
	};
}