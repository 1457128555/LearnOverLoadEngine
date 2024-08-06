#include "Core/Application.h"

#include "Time/Clock.h"

namespace Game
{
	Application::Application() :mGame(mContext)
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		Tool::Clock clock;

		while (IsRunning())
		{
			mGame.preUpdate();
			mGame.update(clock.getDeltaTime());
			mGame.postUpdate();

			clock.update();
		}
	}

	bool Application::IsRunning() const
	{
		return true;
	}
}