#pragma once

#include "../Rust.hpp"

namespace Rust
{
	namespace Cache
	{
		class CWorld
		{
		private:
			void Cache()
			{
				while (true)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(15));

					std::vector<SDK::World::Player> Player = std::vector<SDK::World::Player>();

					for (std::size_t Index = 0; Index < Rust::Cache::Entity->Player.size(); Index++)
					{
						Player.push_back(SDK::World::Player(Rust::Cache::Entity->Player[Index]));
					}

					this->Player = Player;
				}
			}
		public:
			std::vector<SDK::World::Player> Player = std::vector<SDK::World::Player>();

			void Run()
			{
				std::thread([&]() { this->Cache(); }).detach();
			}
		};

		inline Rust::Cache::CWorld* World = new Rust::Cache::CWorld();
	}
}