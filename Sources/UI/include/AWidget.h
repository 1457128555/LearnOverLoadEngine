#pragma once

#include "IDrawable.h"
#include "Pluginable.h"
#include "DataDispatcher.h"

#include <string>

namespace UI
{
	class WidgetContainer;

	class AWidget : public IDrawable, public Pluginable
	{
	public:
		AWidget();

		virtual void draw() override;

		void linkto(const AWidget& widget)					{ mWidgetID = widget.mWidgetID; };
		void destroy()										{ mDestory = true; };
		bool isDestroyed()							const	{ return mDestory; };
		void setParent(WidgetContainer* parent)				{ mParent = parent; };
		bool hasParent()							const	{ return mParent; };
		WidgetContainer* getParent()						{ return mParent; };

	protected:
		virtual void _DrawImpl() = 0;

	public:
		bool				mEnabled			=	true;
		bool				mLinkBreak			=	true;

	protected:
		WidgetContainer*	mParent				=	nullptr;
		std::string			mWidgetID			=	"?";
		bool				mAutoExecutePlugins =	true;

	private:
		bool				mDestory			=	false;
		inline static uint64_t __WIDGET_ID_INCREMENT = 0;
	};
}