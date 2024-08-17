#pragma once

#include "IPlugin.h"

#include <functional>

namespace UI
{
	template<typename T>
	class DataDispatcher : public IPlugin
	{
	public:
		void registerReference(T& reference)
		{
			mDataPointer = &reference;
		}

		void registerProvider(std::function<void(T)> provider)
		{
			mProvider = provider;
		}

		void registerGatherer(std::function<T(void)> gatherer)
		{
			mGatherer = gatherer;
		}

		void provide(T data)
		{
			if (mValueChanged)
			{
				if (mDataPointer)
					*mDataPointer = data;
				else
					mProvider(data);

				mValueChanged = false;
			}
		}

		void notifyChange()
		{
			mValueChanged = true;
		}

		T gather()
		{
			return mDataPointer ? *mDataPointer : mGatherer();
		}

		virtual void execute() override {};

	private:
		bool					mValueChanged = false;
		T*						mDataPointer = nullptr;
		std::function<void(T)>	mProvider;
		std::function<T(void)>	mGatherer;
	};
}