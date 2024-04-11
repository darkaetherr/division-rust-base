#pragma once

#include "../SDK.h"

namespace SDK
{
	class ItemDefinition
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}
		
		std::string DisplayName()
		{
			return Driver->ReadWString(Driver->Read<std::uint64_t>(this->Address() + Offset::ItemDefinition::displayName) + Offset::Translate_Phrase::english);
		}

		std::string Name()
		{
			return Driver->ReadWString(this->Address() + Offset::ItemDefinition::shortname);
		}

		int ID()
		{
			return Driver->Read<int>(this->Address() + Offset::ItemDefinition::itemid);
		}
	};
}