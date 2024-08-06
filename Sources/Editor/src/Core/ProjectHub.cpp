#include "Core/ProjectHub.h"

#include "Windowing.h"

namespace Editor
{
	ProjectHub::ProjectHub()
	{
		_SetupContext();

	}

	void ProjectHub::_SetupContext()
	{
		Window::DeviceSetting deviceSet;
		Window::WindowSettings windowSet = {
			.title = "Project Hub",
			.width = 1000u,
			.height = 580u
		};

		mDevice = std::make_unique<Window::Device>(deviceSet);
		mWindow = std::make_unique<Window::Windowing>(*mDevice, windowSet);
		mWindow->makeCurrentContext();

		int monWidth = 0, monHeight = 0;
		mDevice->GetMonitorSize(monWidth, monHeight);
		int winWidth = 0, winHeight = 0;
		mWindow->getSize(winWidth, winHeight);
		mWindow->setPosition(monWidth / 2 - winWidth / 2, monHeight / 2 - winHeight / 2);


	}

	std::tuple<bool, std::string, std::string> ProjectHub::run()
	{
		while (true)
		{

		}
		return std::tuple<bool, std::string, std::string>();
	}
}