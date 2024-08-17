#pragma once

#include "Windowing.h"
#include "Context/Driver.h"
#include "UIManager.h"
#include "PanelWindow.h"
#include "Canvas.h"

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
		std::unique_ptr<Rendering::Driver>	mDriver;
		std::unique_ptr<UI::UIManager>		mUIManager;

		std::unique_ptr<UI::Canvas>			mCanvas;
		std::unique_ptr<UI::PanelWindow>	mMainPanel;

		std::string mProjectPath = "";
		std::string mProjectName = "";
		bool mReadyToGo = false;
	};
}

