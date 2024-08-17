#pragma once

#include "APanel.h"
#include "Alignment.h"

#include <glm/glm.hpp>

namespace UI
{
	class APanelTransformable : public APanel
	{
	public:
		APanelTransformable(
			const glm::vec2& pos = { -1.f, -1.f },
			const glm::vec2& size = { -1.f, -1.f },
			EHorizontalAlignment hAlignment = EHorizontalAlignment::LEFT,
			EVerticalAlignment vAlignment = EVerticalAlignment::TOP,
			bool ignoreConfigFile = false);

		void setPosition(const glm::vec2& pos);
		void setSize(const glm::vec2& size);
		void setAlignment(EHorizontalAlignment hAlignment, EVerticalAlignment vAlignment);

		const glm::vec2&	getPosition()				const;
		const glm::vec2&	getSize()					const;
		EHorizontalAlignment	getHorizontalAlignment()	const;
		EVerticalAlignment		getVerticalAlignment()		const;

	protected:
		void update();
		virtual void _DrawImpl() = 0;

	private:
		glm::vec2 _CalculatePositionAlignmentOffset(bool defaultFlag = false);
		void _UpdatePosition();
		void _UpdateSize();
		void _CopyImGuiPosition();
		void _CopyImGuiSize();

	public:
		bool mAutoSize = true;

	protected:
		glm::vec2				mDefaultPos			=	glm::vec2(0.f);
		glm::vec2				mDefaultSize		=	glm::vec2(0.f);
		EHorizontalAlignment	mDefaultHAlignment	=	EHorizontalAlignment::LEFT;
		EVerticalAlignment		mDefaultVAlignment	=	EVerticalAlignment::TOP;
		bool					mIgnoreConfigFile	=	false;

		glm::vec2				mPos				=	glm::vec2(0.f);
		glm::vec2				mSize				=	glm::vec2(0.f);
		EHorizontalAlignment	mHAlignment			=	EHorizontalAlignment::LEFT;
		EVerticalAlignment		mVAlignment			=	EVerticalAlignment::TOP;
		bool					mPosChanged			=	false;
		bool					mSizeChanged		=	false;
		bool					mAlignmentChanged	=	false;
		bool					mFirstFrame			=	true;
	};
}

