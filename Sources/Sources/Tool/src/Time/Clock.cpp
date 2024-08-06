#include "Time/Clock.h"

namespace Tool
{
	void Clock::update()
	{
		mLastTime = mCurTime;
		mCurTime = std::chrono::steady_clock::now();
		mElapsed = mCurTime - mLastTime;

		if (mInit)
		{
			mDeltaTime = (float)mElapsed.count() > 0.1f ? 0.1f : (float)mElapsed.count();
			mTimeSinceStart += mDeltaTime * mTimeScale;
		}
		else
			_initialize();
	}

	float Clock::getFramerate()
	{
		return 1.f / mDeltaTime;
	}

	float Clock::getDeltaTime()
	{
		return mDeltaTime;
	}

	float Clock::getDeltaTimeUnscaled()
	{
		return mDeltaTime;
	}

	float Clock::getTimeSinceStart()
	{
		return mTimeSinceStart;
	}

	float Clock::getTimeScale()
	{
		return mTimeScale;
	}

	void Clock::scale(float v)
	{
		mTimeScale *= v;
	}

	void Clock::setTimeScale(float v)
	{
		mTimeScale = v;
	}

	void Clock::_initialize()
	{
		mDeltaTime = 0.f;
		mStartTime = std::chrono::steady_clock::now();
		mCurTime = mStartTime;
		mLastTime = mStartTime;

		mInit = true;
	}
}