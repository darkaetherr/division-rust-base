#pragma once

#include "../SDK.h"

namespace SDK
{
	class PlayerEyes
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		Math::Vector4 BodyRotation()
		{
			return Driver->Read<Math::Vector4>(this->Address() + Offset::PlayerEyes::bodyRotation__BackingField);
		}

		void BodyRotation(Math::Vector4 Value)
		{
			Driver->Write<Math::Vector4>(this->Address() + Offset::PlayerEyes::bodyRotation__BackingField, Value);
		}
	};
}