#pragma once

#include "EStyle.h"

#include <string>
#include <unordered_map>

struct GLFWwindow;
struct ImFont;

namespace UI
{
	class Canvas;

	class UIManager
	{
	public:
		UIManager(GLFWwindow*, EStyle = EStyle::IM_DARK_STYLE, const std::string & = "#version 150");
		~UIManager();

		void enableDocking(bool);
		void applyStyle(EStyle);

		bool loadFont(const std::string& id, const std::string& path, float fontSize);
		bool unloadFont(const std::string& id);
		bool useFont(const std::string& id);

		void enableEditorLayoutSave(bool value);

		void render();

		void removeCanvas()				{ mCurCanvas = nullptr; };
		void setCanvas(Canvas* canvas)	{ mCurCanvas = canvas; };

	private:
		bool mDockingState = false;;
		Canvas* mCurCanvas = nullptr;
		std::unordered_map<std::string, ImFont*> mFonts;
		std::string mLayoutSaveFilename = "imgui.ini";

	};
}

