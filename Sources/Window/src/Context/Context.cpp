#include "Context\Context.h"

#include "iostream"

#include "glfw3.h"

namespace Window
{
	Device::Device(const DeviceSetting& set)
	{
		_BindErrorCallback();
		if (glfwInit() == GLFW_FALSE)
		{
			throw std::runtime_error("Failed to Init GLFW");
			glfwTerminate();
		}

		if(set.debugProfile)
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, set.majorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, set.minorVersion);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_SAMPLES, p_deviceSettings.samples);
	}

	Device::~Device()
	{
		glfwTerminate();
	}

	void Device::pollEvents() const
	{
		glfwPollEvents();
	}

	void Device::GetMonitorSize(int& width, int& height)
	{
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		width = mode->width;
		height = mode->height;
		//return { mode->width , mode->height };
	}

	void Device::_BindErrorCallback()
	{
		//	暂时只是输出错误信息
		auto errorCallBack = [](int code, const char* log) {
			std::cout << "Error[" << code << "]\t Message:" << log << std::endl;
		};
		
		glfwSetErrorCallback(errorCallBack);
	}

}