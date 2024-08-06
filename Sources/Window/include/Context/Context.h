#pragma once

#include "Settings/DeveceSetting.h"

namespace Window
{
	class Device
	{
	public:
		Device(const DeviceSetting&);
		~Device();

		void pollEvents() const;

		static void GetMonitorSize(int&, int&);
	private:
		void _BindErrorCallback();
		

	};

}


