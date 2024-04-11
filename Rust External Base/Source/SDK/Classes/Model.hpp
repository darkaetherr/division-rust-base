#pragma once

#include "../SDK.h"

namespace SDK
{
	class Model
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		SDK::Unity::Transform* Bone(std::uint32_t Index)
		{
			return Driver->Read<SDK::Unity::Transform*>(Driver->Read<std::uint64_t>(Driver->Read<std::uint64_t>(this->Address() + 0x48) + (0x20 + ((std::uint32_t)Index * sizeof(std::uint64_t)))) + 0x10);
		}

		SDK::Unity::Array* List()
		{
			return Driver->Read<SDK::Unity::Array*>(this->Address() + 0x48);
		}
	};
}