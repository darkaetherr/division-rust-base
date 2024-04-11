#pragma once

#include "../SDK.h"

namespace SDK
{
	class Item
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		SDK::BaseProjectile* BaseProjectile()
		{
			return Driver->Read<SDK::BaseProjectile*>(this->Address() + Offset::Item::heldEntity);
		}

		SDK::ItemDefinition* ItemDefinition()
		{
			return Driver->Read<SDK::ItemDefinition*>(this->Address() + Offset::Item::info);
		}

		unsigned int ID()
		{
			return Driver->Read<unsigned int>(this->Address() + Offset::Item::uid);
		}
	};
}