#pragma once

#include "../Rust.hpp"

namespace Rust
{
	namespace Cache
	{
		class CEntity
		{
		private:
			void Cache()
			{
				while (true)
				{
					std::this_thread::sleep_for(std::chrono::seconds(1));

					SDK::Unity::BufferList* List = SDK::BaseNetworkable::List();

					if (!List)
					{
						continue;
					}

					const std::uint64_t Start = List->Start();

					if (!Start)
					{
						continue;
					}

					const std::uint32_t Size = List->Size();

					if (!Size)
					{
						continue;
					}

					std::vector<SDK::BasePlayer*> Player = std::vector<SDK::BasePlayer*>();

					for (std::uint32_t Index = 0; Index < Size; Index++)
					{
						SDK::BaseNetworkable* Networkable = List->Get<SDK::BaseNetworkable*>(Start, Index);
						const std::uint32_t ID = Networkable->Id();

						switch (ID)
						{
						case SDK::Enum::Prefab::player:
							Player.push_back(Networkable->Get<SDK::BasePlayer*>());
						}
					}

					this->Player = Player;
				}
			}
		public:
			std::vector<SDK::BasePlayer*> Player = std::vector<SDK::BasePlayer*>();

			void Run()
			{
				std::thread([&]() { this->Cache(); }).detach();
			}
		};

		inline Rust::Cache::CEntity* Entity = new Rust::Cache::CEntity();
	}
}