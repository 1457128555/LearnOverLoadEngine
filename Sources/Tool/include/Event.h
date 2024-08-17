#pragma once

#include <functional>
#include <unordered_map>

namespace Tool
{
	using ListenerID = uint64_t;

	template<class... ArgTypes>
	class Event
	{
	public:
		using Callback = std::function<void(ArgTypes...)>;

		ListenerID addListener(Callback p_callback)
		{
			ListenerID curID = mAvailableListenerID++;
			mCallbacks[curID] = p_callback;
			return curID;
		}

		ListenerID operator+=(Callback p_callback)
		{
			return addListener(p_callback);
		}

		bool removeListener(ListenerID p_listenerID)
		{
			return mCallbacks.erase(p_listenerID) != 0;
		}

		bool operator-=(ListenerID p_listenerID)
		{
			return removeListener(p_listenerID);
		}

		void removeAllListeners() { mCallbacks.clear(); };

		uint64_t getListenerCount() const { return mCallbacks.size(); };

		void invoke(ArgTypes... p_args)
		{
			for (auto&& it : mCallbacks)
				it.second(p_args...);
		}

	private:
		std::unordered_map<ListenerID, Callback>	mCallbacks;
		ListenerID									mAvailableListenerID = 0;
	};
}