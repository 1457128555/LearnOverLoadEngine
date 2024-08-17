#pragma once

#include "Settings/EGraphicsBackend.h"
#include "Data/PipelineState.h"

#include <optional>

namespace Rendering
{
	template<EGraphicsBackend Backend>
	class GraphicsAPI final
	{
	public:
		std::optional<PipelineState> init(bool);

		std::string getVendor();
		std::string getHardware();
		std::string getVersion();
		std::string getShadingLanguageVersion();
	private:

	};
	using None		=	GraphicsAPI<EGraphicsBackend::NONE>;
	using OpenGL	=	GraphicsAPI<EGraphicsBackend::OPENGL>;
}


