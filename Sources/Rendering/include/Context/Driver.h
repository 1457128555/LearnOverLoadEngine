#pragma once

#include "Settings/DriverSettings.h"

namespace Rendering
{
	class Driver final
	{
	public:
		Driver(const DriverSettings&);
		~Driver();

	private:
		std::string mVendor;
		std::string mHardware;
		std::string mVersion;
		std::string mShadingLanguageVersion;
	};
}

