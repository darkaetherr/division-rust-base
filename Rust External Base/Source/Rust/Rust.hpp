#pragma once

#include "../Dependencies/Window/Window.h"
#include "../Dependencies/Dependencies.h"
#include "../SDK/SDK.h"

#include "Cache/Cache.h"

#include "../Dependencies/Window/Menu/Menu.hpp"
#include "../Dependencies/Window/Draw/Draw.hpp"

namespace Rust
{
	int Entry()
	{
		if (!Driver->Attach("RustClient.exe"))
		{
			return 0x01;
		}

		if (!Storage->Setup())
		{
			return 0x02;
		}

		if (!Window->Valid)
		{
			return 0x03;
		}

		// Initilizing Threads
		{
			Rust::Cache::Run();
		}

		return Window->Render(FindWindowA("UnityWndClass", "Rust"), Menu::Callback, Draw::Callback);
	}
}