#pragma once

#include "../Rust.hpp"

#include "Entity.hpp"
#include "World.hpp"

namespace Rust
{
	namespace Cache
	{
		void Run()
		{
			Rust::Cache::Entity->Run();
			Rust::Cache::World->Run();
		}
	}
}