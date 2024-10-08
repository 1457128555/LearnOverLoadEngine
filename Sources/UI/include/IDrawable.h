#pragma once

namespace UI
{
	//	Interface for any drawable class
	class IDrawable
	{
	public:
		virtual void draw() = 0;
	protected:
		virtual ~IDrawable() = default;
	};
}