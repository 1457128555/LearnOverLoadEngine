#pragma once

#include "Context/Context.h"
#include "Settings/WindowSetting.h"

struct GLFWwindow;

namespace Window
{
	class Windowing
	{
	public:
		Windowing(const Device&, const WindowSettings&);
		~Windowing();

		void makeCurrentContext()	const;
		void getSize(int&, int&)	const;
		bool shouldClose()			const;
		void swapBuffers()			const;


		void setPosition(int, int);

		GLFWwindow* getWindowHandle()const { return mHandle; };
	private:
		void _CreateGlfwWindow(const WindowSettings&);

	private:
		const Device&	mDevice;
		GLFWwindow*		mHandle		=	nullptr;
		std::string		mTitle		=	"";
		uint32_t		mWidth		=	0u;
		uint32_t		mHeight		=	0u;
	};
}

