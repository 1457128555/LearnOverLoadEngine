#include "Canvas.h"

#include "APanel.h"

#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_opengl3.h>
#include <ImGui/imgui_impl_glfw.h>

namespace UI
{
	void Canvas::addPanel(APanel* panel)
	{
		mPanels.push_back(panel);
	}

	void Canvas::removePanel(APanel* panel)
	{
		for (auto it = mPanels.begin(); it != mPanels.end(); it++)
		{
			if (*it == panel)
			{
				mPanels.erase(it);
				return;
			}
		}
	}

	void Canvas::removeAllPanels()
	{
		mPanels.clear();
	}

	void Canvas::makeDockSpace(bool state)
	{
		mIsDock = state;
	}

	bool Canvas::isDockSpace() const
	{
		return mIsDock;
	}

	void Canvas::draw()
	{
		//if (mPanels.empty()) return;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (mIsDock)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

			ImGui::Begin("##dockspace", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking);
			ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);
			ImGui::SetWindowPos({ 0.f, 0.f });
			ImVec2 displaySize = ImGui::GetIO().DisplaySize;
			ImGui::SetWindowSize({ (float)displaySize.x, (float)displaySize.y });
			ImGui::End();

			ImGui::PopStyleVar(3);
		}

		for (auto&& panel : mPanels)
			panel->draw();

		ImGui::Render();
	}
}