#include "Core/ProjectHub.h"

#include "Windowing.h"

#include <filesystem>
#include <fstream>

#include <glm/glm.hpp>

#include <ImGui/imgui.h>

namespace
{
	const std::string PROJECTS_FILE = std::string(std::string(getenv("APPDATA")) + "\\OverloadTech\\OvEditor\\projects.ini");

	class ProjectHubPanel : public UI::PanelWindow
	{
	public:
		ProjectHubPanel(bool& readyToGo, std::string& path, std::string& projectName)
			:PanelWindow("Project Hub", true), 
			mReadyToGo(readyToGo),
			mPath(path),
			mProjectName(projectName)
		{
			mSet.resizable = false;
			mSet.movable = false;
			mSet.titleBar = false;

			//	在系统的AppData目录下创建文件夹
			std::filesystem::create_directories(std::string(getenv("APPDATA")) + "\\OverloadTech\\OvEditor\\");

			setSize({ 1000.f, 580.f });
			setPosition({ 0.f, 0.f });


		}

		void draw() override
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 50.f, 50.f });
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);

			UI::PanelWindow::draw();

			ImGui::PopStyleVar(2);
		}

	private:
		bool& mReadyToGo;
		std::string& mPath;
		std::string& mProjectName;
		//OvUI::Widgets::Buttons::Button* m_goButton = nullptr;
	};
}


namespace Editor
{
	ProjectHub::ProjectHub()
	{
		_SetupContext();
		mMainPanel = std::make_unique<ProjectHubPanel>(mReadyToGo, mProjectPath, mProjectName);

		mCanvas = std::make_unique<UI::Canvas>();
		mUIManager->setCanvas(mCanvas.get());
		mCanvas->addPanel(mMainPanel.get());
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

		/* Graphics context creation */
		mDriver = std::make_unique<Rendering::Driver>(Rendering::DriverSettings{ false });

		mUIManager = std::make_unique<UI::UIManager>(mWindow->getWindowHandle(), UI::EStyle::ALTERNATIVE_DARK);
		mUIManager->loadFont("Ruda_Big", "../../asset/Fonts/Ruda-Bold.ttf", 18);
		mUIManager->useFont("Ruda_Big");
		mUIManager->enableEditorLayoutSave(false);
		mUIManager->enableDocking(false);
	}

	std::tuple<bool, std::string, std::string> ProjectHub::run()
	{
		while (!mWindow->shouldClose())
		{
			mDevice->pollEvents();
			mUIManager->render();
			mWindow->swapBuffers();
		}
		return std::tuple<bool, std::string, std::string>();
	}
}