#pragma once

#include "../ImGui/imgui.h"

namespace Menu
{
	void Callback()
	{
		using namespace ImGui;

		Begin("Window", nullptr);

		Text("Hello World");

		End();
	}
}