#pragma once

#include "../SDK.h"

namespace SDK
{
	class PlayerInput
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		Math::Vector3 BodyAngles()
		{
			return Driver->Read<Math::Vector3>(this->Address() + Offset::PlayerInput::bodyAngles);
		}

		void BodyAngles(Math::Vector3 Value)
		{
			Driver->Write<Math::Vector3>(this->Address() + Offset::PlayerInput::bodyAngles, Value);
		}
	};
}