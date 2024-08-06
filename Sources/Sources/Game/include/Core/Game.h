#pragma once

#include "Core/Context.h"

namespace Game
{
	class Game
	{
	public:
		Game(Context&);
		~Game();

		void preUpdate();							//	Pre-update of the game logic
		void update(float p_deltaTime);				//	Update the game logic
		void postUpdate();							//	Post-update of the game logic

	private:
		Context& mContext;
	};
}

