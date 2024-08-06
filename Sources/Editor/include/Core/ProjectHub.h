#pragma once

#include "Windowing.h"

#include <string>
#include <tuple>
#include <memory>

namespace Editor
{
	class ProjectHub
	{
	public:
		ProjectHub();

		std::tuple<bool, std::string, std::string> run();

	private:
		void _SetupContext();

	private:
		std::unique_ptr<Window::Device>		mDevice;
		std::unique_ptr<Window::Windowing>	mWindow;
	};
}

