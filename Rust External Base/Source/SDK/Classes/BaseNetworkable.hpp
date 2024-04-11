#pragma once

#include "../SDK.h"

namespace SDK
{
	class BaseNetworkable
	{
	private:
	public:
		static SDK::Unity::BufferList* List()
		{
			return Driver->ReadChain<SDK::Unity::BufferList*>(Storage->GameAssembly, { Offset::System_Collections_Generic_List_BaseGameMode_, 0xB8, 0x10, 0x10, 0x28 });
		}
		
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		unsigned int Id()
		{
			return Driver->Read<unsigned int>(this->Address() + Offset::BaseNetworkable::prefabID);
		}

		std::string Name()
		{
			return Driver->ReadString(Driver->Read<std::uint64_t>(this->Address() + 0x00) + 0x10);
		}

		template<typename Type>
		Type Get()
		{
			return Driver->ReadChain<Type>(this->Address(), {0x10, 0x28});
		}
	};
}