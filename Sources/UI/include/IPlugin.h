#pragma once

namespace UI
{
	class IPlugin
	{
	public:
		virtual void execute() = 0;
		void* userData = nullptr;
	};
}