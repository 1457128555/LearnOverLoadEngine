#pragma once

#include <chrono>

namespace Tool
{
	class Clock
	{
	public:
		void	update();						//	Update the clock
		float	getFramerate();					//	Return the actual framerate (Depend on the delta time)
		float	getDeltaTime();					//	Return the actual delta time (Scale applied)
		float	getDeltaTimeUnscaled();			//	Return the actual delta time (Scale not applied)
		float	getTimeSinceStart();			//	Return the time elapsed since clock creation
		float	getTimeScale();					//	Return the current timescale
		void	scale(float);					//	Multiply the timescale by the given coefficient
		void	setTimeScale(float);			//	Define a timescale
	private:
		void	_initialize();

		std::chrono::steady_clock::time_point	mStartTime;
		std::chrono::steady_clock::time_point	mLastTime;
		std::chrono::steady_clock::time_point	mCurTime;
		std::chrono::duration<double>			mElapsed;

		bool	mInit				=	false;
		float	mTimeScale			=	1.f;
		float	mDeltaTime			=	0.f;
		float	mTimeSinceStart		=	0.f;
	};
}

