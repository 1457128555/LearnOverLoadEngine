#include "Windowing.h"

#include <glfw3.h>
#include <stdexcept>

namespace Window
{
	Windowing::Windowing(const Device& device, const WindowSettings& set)
		:mDevice(device), 
		mTitle(set.title),
		mWidth(set.width),
		mHeight(set.height)
	{
		_CreateGlfwWindow(set);

	}

	Windowing::~Windowing()
	{
		glfwDestroyWindow(mHandle);
	}

	void Windowing::makeCurrentContext() const
	{
		glfwMakeContextCurrent(mHandle);
	}

	void Windowing::getSize(int& w, int& h) const
	{
		glfwGetWindowSize(mHandle, &w, &h);
	}

	bool Windowing::shouldClose()const
	{
		return glfwWindowShouldClose(mHandle);
	}

	void Windowing::swapBuffers()const
	{
		glfwSwapBuffers(mHandle);
	}

	void Windowing::setPosition(int x, int y)
	{
		glfwSetWindowPos(mHandle, x, y);
	}

	void Windowing::_CreateGlfwWindow(const WindowSettings& set)
	{
		mHandle = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
		if (!mHandle) throw std::runtime_error("Failed to create GLFW window");
	}
}