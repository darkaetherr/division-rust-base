#pragma once

#include "../SDK.h"

namespace SDK
{
	class BasePlayer : public SDK::BaseCombatEntity
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		static SDK::BasePlayer* Instance()
		{
			return Driver->ReadChain<SDK::BasePlayer*>(Storage->GameAssembly, { Offset::LocalPlayer, 0xB8, 0x00 });
		}

		unsigned int ActiveID()
		{
			return Driver->Read<unsigned int>(this->Address() + Offset::BasePlayer::clActiveItem);
		}

		SDK::Item* GetHeldItem()
		{
			SDK::PlayerInventory* PlayerInventory = this->PlayerInventory();

			if (!PlayerInventory)
			{
				return nullptr;
			}

			SDK::ItemContainer* ItemContainer = PlayerInventory->Belt();

			if (!ItemContainer)
			{
				return nullptr;
			}

			SDK::Unity::List* List = ItemContainer->Contents();

			if (!List)
			{
				return nullptr;
			}

			const unsigned int ActiveId = this->ActiveID();
			const std::uint64_t Start = List->Start();
			const std::uint32_t Size = List->Size();

			for (std::uint32_t Index = 0; Index < Size; Index++)
			{
				SDK::Item* Item = List->Get<SDK::Item*>(Start, Index);

				if (Item->ID() == ActiveId)
				{
					return Item;
				}
			}

			return nullptr;
		}

		SDK::PlayerWalkMovement* PlayerWalkMovement()
		{
			return Driver->Read<SDK::PlayerWalkMovement*>(this->Address() + Offset::BasePlayer::movement);
		}

		SDK::PlayerInventory* PlayerInventory() 
		{
			return Driver->Read<SDK::PlayerInventory*>(this->Address() + Offset::BasePlayer::inventory);
		}

		SDK::PlayerInput* PlayerInput()
		{
			return Driver->Read<SDK::PlayerInput*>(this->Address() + Offset::BasePlayer::input);
		}

		SDK::PlayerEyes* PlayerEyes()
		{
			return Driver->Read<SDK::PlayerEyes*>(this->Address() + Offset::BasePlayer::eyes);
		}

		SDK::PlayerModel* PlayerModel()
		{
			return Driver->Read<SDK::PlayerModel*>(this->Address() + Offset::BasePlayer::playerModel);
		}

		std::string Name()
		{
			return Driver->ReadWString(this->Address() + Offset::BasePlayer::_displayName);
		}

		void CurrentViewMode(std::uint32_t Value)
		{
			Driver->Write<std::uint32_t>(this->Address() + Offset::BasePlayer::currentViewMode, Value);
		}

		void SelectedViewMode(std::uint32_t Value)
		{
			Driver->Write<std::uint32_t>(this->Address() + Offset::BasePlayer::selectedViewMode, Value);
		}

		void RemoveFlag(std::uint32_t Value)
		{
			std::uint32_t Flags = Driver->Read<std::uint32_t>(this->Address() + Offset::BasePlayer::playerFlags);

			if (this->HasFlag(Value))
			{
				Flags -= Value;

				Driver->Write<std::uint32_t>(this->Address() + Offset::BasePlayer::playerFlags, Flags);
			}
		}

		void AddFlag(std::uint32_t Value)
		{
			const std::uint32_t Flags = Driver->Read<std::uint32_t>(this->Address() + Offset::BasePlayer::playerFlags);
			Driver->Write<std::uint32_t>(this->Address() + Offset::BasePlayer::playerFlags, Flags | Value);
		}

		bool HasFlag(std::uint32_t Value)
		{
			return (Driver->Read<std::uint32_t>(this->Address() + Offset::BasePlayer::playerFlags)) & Value;
		}

		unsigned long TeamID()
		{
			return Driver->Read<unsigned long>(this->Address() + Offset::BasePlayer::currentTeam);
		}
	};
}