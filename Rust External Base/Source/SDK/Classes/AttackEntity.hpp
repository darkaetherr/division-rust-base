#pragma once

#include "../SDK.h"

namespace SDK
{
	class AttackEntity
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		void RepeatDelay(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::AttackEntity::repeatDelay, Value);
		}

		float RepeatDelay()
		{
			return Driver->Read<float>(this->Address() + Offset::AttackEntity::repeatDelay);
		}
	};
}