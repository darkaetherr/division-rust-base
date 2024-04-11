#pragma once

#include "../SDK.h"

namespace SDK
{
	class BaseEntity
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		Math::Vector3 Position()
		{
			return Driver->Read<Math::Vector3>(Driver->ReadChain<std::uint64_t>(this->Address(), {0x10, 0x30,0x30,0x8,0x38}) + 0x90);
		}

		SDK::Model* Model()
		{
			return Driver->Read<SDK::Model*>(this->Address() + Offset::BaseEntity::model);
		}
	};
}