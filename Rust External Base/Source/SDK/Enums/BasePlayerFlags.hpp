#pragma once

#include "../SDK.h"

namespace SDK
{
	namespace Enum
	{
		enum BasePlayerFlags : std::uint32_t
		{
			Unused1 = 1,
			Unused2 = 2,
			IsAdmin = 4,
			ReceivingSnapshot = 8,
			Sleeping = 16,
			Spectating = 32,
			Wounded = 64,
			IsDeveloper = 128,
			Connected = 256,
			ThirdPersonViewmode = 1024,
			EyesViewmode = 2048,
			ChatMute = 4096,
			NoSprint = 8192,
			Aiming = 16384,
			DisplaySash = 32768,
			Relaxed = 65536,
			SafeZone = 131072,
			ServerFall = 262144,
			Incapacitated = 524288,
			Workbench1 = 1048576,
			Workbench2 = 2097152,
			Workbench3 = 4194304
		};
	}
}