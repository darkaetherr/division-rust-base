#pragma once

#include "../SDK.h"

namespace SDK
{
	class UIInventory
	{
	private:
	public:
		static bool IsOpen()
		{
			return Driver->Read<bool>(Driver->ReadChain<std::uint64_t>(Storage->GameAssembly, { Offset::UIInventory, 0xB8 }));
		}
	};
}