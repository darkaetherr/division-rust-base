#pragma once

#include "../../../Rust/Rust.hpp"
#include "../ImGui/imgui.h"

namespace Draw
{
	void Callback()
	{
		using namespace ImGui;

		ImDrawList* Renderer = GetBackgroundDrawList();

		SDK::Unity::Camera::Matrix ViewMatrix = SDK::Unity::Camera::Instance()->ViewMatrix();

		for (std::size_t Index = 0; Index < Rust::Cache::World->Player.size(); Index++)
		{
			SDK::Screen::Player(Rust::Cache::World->Player[Index], ViewMatrix).Render(Renderer);
		}
	}
}