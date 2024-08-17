#pragma once

#include "IPlugin.h"
#include <vector>

namespace UI
{
	//	Inherit from this class to make your class "Pluginable" (Able to have plugins)
	class Pluginable
	{
	public:
		virtual ~Pluginable()
		{
			removeAllPlugins();
		}

		//	Add a plugin
		template<typename T, typename... Args>
		T& addPlugin(Args&& ... args)
		{
			static_assert(std::is_base_of<IPlugin, T>::value, "T should derive from IPlugin");
			T* newPlugin = new T(std::forward<Args>(args)...);
			mPlugins.push_back(newPlugin);
			return *newPlugin;
		}

		template<typename T>
		T* getPlugin()
		{
			static_assert(std::is_base_of<IPlugin, T>::value, "T should derive from IPlugin");
			for (IPlugin* plugin : mPlugins)
			{
				T* result = (T*)plugin;
				if (result)
					return result;
			}
			return nullptr;
		}

		void executePlugins()
		{
			for (IPlugin* plugin : mPlugins)
				plugin->execute();
		}

		void removeAllPlugins()
		{
			for (IPlugin* plugin : mPlugins)
				delete plugin;
			mPlugins.clear();
		}

	private:
		std::vector<IPlugin*> mPlugins;
	};
}