#pragma once

#include "../SDK.h"

namespace SDK
{
	namespace Enum
	{
		enum ModelStateFlags : std::uint32_t
		{
			ModelStateDucked = 1,
			ModelStateJumped,
			ModelStateOnGround = 4,
			ModelStateSleeping = 8,
			ModelStateSprinting = 16,
			ModelStateOnLadder = 32,
			ModelStateFlying = 64,
			ModelStateAiming = 128,
			ModelStateProne = 256,
			ModelStateMounted = 512,
			ModelStateRelaxed = 1024,
			ModelStateOnPhone = 2048,
			ModelStateCrawling = 4096,
			ModelStateHeadLook = 16384
		};
	}
}