#include "Context/Driver.h"
#include "HAL/GraphicsAPI.h"

#include <memory>

namespace Rendering
{
	namespace
	{
		using SelectedAPI = OpenGL;
		std::unique_ptr<SelectedAPI> sDriverImpl;
	}

	Driver::Driver(const DriverSettings& set)
	{
		sDriverImpl = std::make_unique<SelectedAPI>();
		auto initialPipelineState = sDriverImpl->init(set.debugModel);

		mVendor = sDriverImpl->getVendor();
		mHardware = sDriverImpl->getHardware();
		mVersion = sDriverImpl->getVersion();
		mShadingLanguageVersion = sDriverImpl->getShadingLanguageVersion();
	}

	Driver::~Driver()
	{
	}
}