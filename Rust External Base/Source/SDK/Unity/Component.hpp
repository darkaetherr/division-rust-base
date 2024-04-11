#pragma once

#include "../SDK.h"

namespace SDK
{
	namespace Unity
	{
		class Component
		{
		private:	
		public:
			template <typename Type>
			static Type Find(std::uint64_t GameObject, std::string Name)
			{
				const std::uint64_t List = Driver->Read<std::uint64_t>(GameObject + 0x30);

				for (std::uint32_t Index = 0; Index < 255; Index++)
				{
					const std::uint64_t Entry = Driver->Read<std::uint64_t>(List + (0x10 * Index + 0x8));

					if (!Entry)
					{
						continue;
					}

					Type Class = Driver->Read<Type>(Entry + 0x28);

					std::string ComponentName = Driver->ReadString(Driver->Read<std::uint64_t>(Driver->Read<std::uint64_t>(Entry + 0x28)) + 0x10);

					if (ComponentName.find(Name) != std::string::npos)
					{	
						return Class;
					}
				}

				return Type();
			}
		};
	}
}