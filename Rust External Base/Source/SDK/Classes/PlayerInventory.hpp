#pragma once

#include "../SDK.h"

namespace SDK
{
	class PlayerInventory
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		SDK::ItemContainer* Belt()
		{
			return Driver->Read<SDK::ItemContainer*>(this->Address() + Offset::PlayerInventory::containerBelt);
		}
	};
}