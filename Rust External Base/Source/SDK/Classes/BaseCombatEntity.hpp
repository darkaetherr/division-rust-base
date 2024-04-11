#pragma once

#include "../SDK.h"

namespace SDK
{
	class BaseCombatEntity : public SDK::BaseEntity
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		float MaxHealth()
		{
			return Driver->Read<float>(this->Address() + Offset::BaseCombatEntity::_maxHealth);
		}

		float Health()
		{
			return Driver->Read<float>(this->Address() + Offset::BaseCombatEntity::_health);
		}

		SDK::Enum::LifeState Lifestate()
		{
			return Driver->Read<SDK::Enum::LifeState>(this->Address() + Offset::BaseCombatEntity::lifestate);
		}
	};
}