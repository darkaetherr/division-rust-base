#pragma once

#include "../SDK.h"

namespace SDK
{
	class PlayerModel
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		bool IsLocalPlayer()
		{
			return Driver->Read<bool>(this->Address() + Offset::PlayerModel::isLocalPlayer);
		}

		bool IsNPC()
		{
			return Driver->Read<bool>(this->Address() + Offset::PlayerModel::IsNpc__BackingField);
		}

		SDK::ModelState* ModelState()
		{
			return Driver->Read<SDK::ModelState*>(this->Address() + Offset::PlayerModel::modelState);
		}

		Math::Vector4 Rotation()
		{
			return Driver->Read<Math::Vector4>(this->Address() + Offset::PlayerModel::rotation);
		}

		Math::Vector3 Velocity()
		{
			return Driver->Read<Math::Vector3>(this->Address() + Offset::PlayerModel::newVelocity);
		}

		Math::Vector3 Position()
		{
			return Driver->Read<Math::Vector3>(this->Address() + Offset::PlayerModel::position);
		}
	};
}