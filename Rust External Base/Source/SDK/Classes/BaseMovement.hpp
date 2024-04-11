#pragma once

#include "../SDK.h"

namespace SDK
{
	class BaseMovement
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		Math::Vector3 TargetMovement()
		{
			return Driver->Read<Math::Vector3>(this->Address() + Offset::BaseMovement::TargetMovement__BackingField);
		}

		void TargetMovement(Math::Vector3 Value)
		{
			Driver->Write<Math::Vector3>(this->Address() + Offset::BaseMovement::TargetMovement__BackingField, Value);
		}

		void Grounded(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseMovement::Grounded__BackingField, Value);
		}

		void AdminCheat(bool Value)
		{
			Driver->Write<bool>(this->Address() + Offset::BaseMovement::adminCheat, Value);
		}
	};
}