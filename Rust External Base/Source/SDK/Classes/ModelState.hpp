#pragma once

#include "../SDK.h"

namespace SDK
{
	class ModelState
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		void RemoveFlag(std::uint32_t Value)
		{
			std::uint32_t Flags = Driver->Read<std::uint32_t>(this->Address() + Offset::ModelState::flags);

			if (this->HasFlag(Value))
			{
				Flags -= Value;

				Driver->Write<std::uint32_t>(this->Address() + Offset::ModelState::flags, Flags);
			}
		}

		void AddFlag(std::uint32_t Value)
		{
			const std::uint32_t Flags = Driver->Read<std::uint32_t>(this->Address() + Offset::ModelState::flags);
			Driver->Write<std::uint32_t>(this->Address() + Offset::ModelState::flags, Flags | Value);
		}

		bool HasFlag(std::uint32_t Value)
		{
			return (Driver->Read<std::uint32_t>(this->Address() + Offset::ModelState::flags)) & Value;
		}

	};
}