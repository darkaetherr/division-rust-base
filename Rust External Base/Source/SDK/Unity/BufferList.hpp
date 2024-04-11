#pragma once

#include "../SDK.h"

namespace SDK
{
	namespace Unity
	{
		class BufferList
		{
		private:
		public:
			std::uint64_t Address()
			{
				return (std::uint64_t)(this);
			}

			template<typename Type>
			Type Get(const std::uint64_t& Start, const std::uint32_t& Index)
			{
				return Driver->Read<Type>(Start + 0x20 + (Index * 0x8));
			}

			std::uint64_t Start()
			{
				return Driver->Read<std::uint64_t>(this->Address() + 0x18);
			}

			std::uint32_t Size()
			{
				return Driver->Read<std::uint32_t>(this->Address() + 0x10);
			}
		};
	}
}