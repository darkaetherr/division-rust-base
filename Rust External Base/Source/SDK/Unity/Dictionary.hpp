#pragma once

#include "../SDK.h"

namespace SDK
{
	namespace Unity
	{
		class Dictionary
		{
		private:
		public:
			std::uint64_t Address()
			{
				return (std::uint64_t)(this);
			}

			SDK::Unity::List* Value()
			{
				return Driver->Read<SDK::Unity::List*>(this->Address() + 0x28);
			}
		};
	}
}