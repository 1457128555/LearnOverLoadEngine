#pragma once

#include "Core/Context.h"
#include "Core/Game.h"

namespace Game
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		bool IsRunning() const;
	private:
		Context mContext;
		Game mGame;
	};
}

