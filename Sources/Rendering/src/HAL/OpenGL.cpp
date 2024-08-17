#include "HAL/GraphicsAPI.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>
#include <string>

namespace Rendering
{
	namespace
	{
#define _LOD(message) std::cout<<message<<std::endl;

		void GLDebugMessageCallback(uint32_t source, uint32_t type, uint32_t id, uint32_t severity, int32_t length, const char* message, const void* userParam)
		{
			// ignore non-significant error/warning codes
			if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

			std::string output;

			output += "OpenGL Debug Message:\n";
			output += "Debug message (" + std::to_string(id) + "): " + message + "\n";

			switch (source)
			{
			case GL_DEBUG_SOURCE_API:				output += "Source: API";				break;
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:		output += "Source: Window System";		break;
			case GL_DEBUG_SOURCE_SHADER_COMPILER:	output += "Source: Shader Compiler";	break;
			case GL_DEBUG_SOURCE_THIRD_PARTY:		output += "Source: Third Party";		break;
			case GL_DEBUG_SOURCE_APPLICATION:		output += "Source: Application";		break;
			case GL_DEBUG_SOURCE_OTHER:				output += "Source: Other";				break;
			}

			output += "\n";

			switch (type)
			{
			case GL_DEBUG_TYPE_ERROR:               output += "Type: Error";				break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: output += "Type: Deprecated Behaviour"; break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  output += "Type: Undefined Behaviour";	break;
			case GL_DEBUG_TYPE_PORTABILITY:         output += "Type: Portability";			break;
			case GL_DEBUG_TYPE_PERFORMANCE:         output += "Type: Performance";			break;
			case GL_DEBUG_TYPE_MARKER:              output += "Type: Marker";				break;
			case GL_DEBUG_TYPE_PUSH_GROUP:          output += "Type: Push Group";			break;
			case GL_DEBUG_TYPE_POP_GROUP:           output += "Type: Pop Group";			break;
			case GL_DEBUG_TYPE_OTHER:               output += "Type: Other";				break;
			}

			output += "\n";

			switch (severity)
			{
			case GL_DEBUG_SEVERITY_HIGH:			output += "Severity: High";				break;
			case GL_DEBUG_SEVERITY_MEDIUM:			output += "Severity: Medium";			break;
			case GL_DEBUG_SEVERITY_LOW:				output += "Severity: Low";				break;
			case GL_DEBUG_SEVERITY_NOTIFICATION:	output += "Severity: Notification";		break;
			}

			switch (severity)
			{
			case GL_DEBUG_SEVERITY_HIGH:			_LOD(output);	break;
			case GL_DEBUG_SEVERITY_MEDIUM:			_LOD(output);	break;
			case GL_DEBUG_SEVERITY_LOW:				_LOD(output);	break;
			case GL_DEBUG_SEVERITY_NOTIFICATION:	_LOD(output);	break;
			}
		}

		PipelineState RetrieveOpenGLPipelineState()
		{
			PipelineState ret;


			return ret;
		}

		std::string GetString(uint32_t p_parameter)
		{
			const GLubyte* result = glGetString(p_parameter);
			return result ? reinterpret_cast<const char*>(result) : std::string();
		}

		std::string GetString(uint32_t p_parameter, uint32_t p_index)
		{
			const GLubyte* result = glGetStringi(p_parameter, p_index);
			return result ? reinterpret_cast<const char*>(result) : std::string();
		}
	}


	std::optional<PipelineState> OpenGL::init(bool debug)
	{

		const GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			std::string message = "Error Init GLEW: ";
			std::string glewError = (const char*)glewGetErrorString(error);
			std::cout << message << glewError << std::endl;
			return std::nullopt;
		}

		if (debug)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(GLDebugMessageCallback, nullptr);
		}

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glCullFace(GL_BACK);

		return RetrieveOpenGLPipelineState();
	}

	std::string OpenGL::getVendor()
	{
		return GetString(GL_VENDOR);
	}

	std::string OpenGL::getHardware()
	{
		return GetString(GL_RENDERER);
	}

	std::string OpenGL::getVersion()
	{
		return GetString(GL_VERSION);
	}

	std::string OpenGL::getShadingLanguageVersion()
	{
		return GetString(GL_SHADING_LANGUAGE_VERSION);
	}
}