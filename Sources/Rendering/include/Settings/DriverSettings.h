#pragma once

#include <optional>

#include "Data/PipelineState.h"

namespace Rendering
{
	struct DriverSettings
	{
		bool debugModel = false;
		std::optional<PipelineState> pipelineState = std::nullopt;
	};
}