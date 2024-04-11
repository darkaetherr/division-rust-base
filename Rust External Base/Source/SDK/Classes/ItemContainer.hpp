#pragma once

#include "../SDK.h"

namespace SDK
{
	class ItemContainer
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		SDK::Unity::List* Contents()
		{
			return Driver->Read<SDK::Unity::List*>(this->Address() + 0x38);
		}
	};
}