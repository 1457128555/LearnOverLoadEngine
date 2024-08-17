#include "APanelTransformable.h"
#include "Converter.h"

namespace UI
{
	APanelTransformable::APanelTransformable(const glm::vec2& pos,
		const glm::vec2& size,
		EHorizontalAlignment hAlignment,
		EVerticalAlignment vAlignment,
		bool ignoreConfigFile)
		:mDefaultPos(pos),
		mDefaultSize(size),
		mDefaultHAlignment(hAlignment),
		mDefaultVAlignment(vAlignment),
		mIgnoreConfigFile(ignoreConfigFile)
	{

	}

	void APanelTransformable::setPosition(const glm::vec2& pos)
	{
		mPos = pos;
		mPosChanged = true;
	}

	void APanelTransformable::setSize(const glm::vec2& size)
	{
		mSize = size;
		mSizeChanged = true;
	}

	void APanelTransformable::setAlignment(EHorizontalAlignment hAlignment, EVerticalAlignment vAlignment)
	{
		mHAlignment = hAlignment;
		mVAlignment = vAlignment;
		mAlignmentChanged = true;
	}

	const glm::vec2& APanelTransformable::getPosition() const
	{
		return mPos;
	}

	const glm::vec2& APanelTransformable::getSize() const
	{
		return mSize;
	}

	EHorizontalAlignment APanelTransformable::getHorizontalAlignment() const
	{
		return mHAlignment;
	}

	EVerticalAlignment APanelTransformable::getVerticalAlignment() const
	{
		return mVAlignment;
	}

	void APanelTransformable::update()
	{
		if (!mFirstFrame)
		{
			if (!mAutoSize)
				_UpdateSize();
			_CopyImGuiSize();
			_UpdatePosition();
			_CopyImGuiPosition();
		}
		mFirstFrame = false;
	}

	glm::vec2 APanelTransformable::_CalculatePositionAlignmentOffset(bool defaultFlag)
	{
		glm::vec2 result(0.f);

		switch (defaultFlag ? mDefaultHAlignment : mHAlignment)
		{
		case EHorizontalAlignment::CENTER:
			result.x -= mSize.x / 2.f;
			break;

		case EHorizontalAlignment::RIGHT:
			result.x -= mSize.x;
			break;
		}

		switch (defaultFlag ? mDefaultVAlignment : mVAlignment)
		{
		case EVerticalAlignment::MIDDLE:
			result.y -= mSize.y / 2.f;
			break;

		case EVerticalAlignment::BOTTOM:
			result.y -= mSize.y;
			break;
		}
		return result;
	}

	void APanelTransformable::_UpdatePosition()
	{
		if (mDefaultPos.x != -1.f && mDefaultPos.y != 1.f)
		{
			glm::vec2 offsetDefaultPos = mDefaultPos + _CalculatePositionAlignmentOffset(true);
			ImGui::SetWindowPos(Converter::ToImVec2(offsetDefaultPos), mIgnoreConfigFile ? ImGuiCond_Once : ImGuiCond_FirstUseEver);
		}

		if (mPosChanged || mAlignmentChanged)
		{
			glm::vec2 offsetPos = mPos + _CalculatePositionAlignmentOffset(false);
			ImGui::SetWindowPos(Converter::ToImVec2(offsetPos), ImGuiCond_Always);
			mPosChanged = false;
			mAlignmentChanged = false;
		}
	}

	void APanelTransformable::_UpdateSize()
	{
		if (mSizeChanged)
		{
			ImGui::SetWindowSize(Converter::ToImVec2(mSize), ImGuiCond_Always);
			mSizeChanged = false;
		}
	}

	void APanelTransformable::_CopyImGuiPosition()
	{
		mPos = Converter::ToFVector2(ImGui::GetWindowPos());
	}

	void APanelTransformable::_CopyImGuiSize()
	{
		mSize = Converter::ToFVector2(ImGui::GetWindowSize());
	}
}