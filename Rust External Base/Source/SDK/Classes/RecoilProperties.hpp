#pragma once

#include "../SDK.h"

namespace SDK
{
	class RecoilProperties
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		Math::Vector2 Yaw()
		{
			return Driver->Read<Math::Vector2>(this->Address() + Offset::RecoilProperties::recoilYawMin);
		}

		Math::Vector2 Pitch()
		{
			return Driver->Read<Math::Vector2>(this->Address() + Offset::RecoilProperties::recoilPitchMin);
		}

		void Yaw(Math::Vector2 Value)
		{
			Driver->Write<Math::Vector2>(this->Address() + Offset::RecoilProperties::recoilYawMin, Value);
		}

		void Pitch(Math::Vector2 Value)
		{
			Driver->Write<Math::Vector2>(this->Address() + Offset::RecoilProperties::recoilPitchMin, Value);
		}

		void AimconeCurveScale(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::RecoilProperties::aimconeCurveScale, Value);
		}

		SDK::RecoilProperties* Override()
		{
			return Driver->Read<SDK::RecoilProperties*>(this->Address() + Offset::RecoilProperties::newRecoilOverride);
		}
	};
}