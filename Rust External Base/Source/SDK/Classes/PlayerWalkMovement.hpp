#pragma once

#include "../SDK.h"

namespace SDK
{
	class PlayerWalkMovement : public SDK::BaseMovement
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		Math::Vector3 PreviousVelocity()
		{
			return Driver->Read<Math::Vector3>(this->Address() + Offset::PlayerWalkMovement::previousVelocity);
		}

		float CapsuleHeightCrawling()
		{
			return Driver->Read<float>(this->Address() + Offset::PlayerWalkMovement::capsuleHeightCrawling);
		}

		float CapsuleHeightDucked()
		{
			return Driver->Read<float>(this->Address() + Offset::PlayerWalkMovement::capsuleHeightDucked);
		}

		float CapsuleHeight()
		{
			return Driver->Read<float>(this->Address() + Offset::PlayerWalkMovement::capsuleHeight);
		}

		void GroundAngleNew(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::groundAngleNew, Value);
		}

		void GroundAngle(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::groundAngle, Value);
		}

		void GroundTime(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::groundTime, Value);
		}

		void LandTime(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::landTime, Value);
		}

		void JumpTime(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::jumpTime, Value);
		}

		void CapsuleHeightCrawling(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::capsuleHeightCrawling, Value);
		}

		void CapsuleHeightDucked(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::capsuleHeightDucked, Value);
		}

		void CapsuleHeight(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::capsuleHeight, Value);
		}

		void CapsuleCenterCrawling(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::capsuleCenterCrawling, Value);
		}

		void CapsuleCenterDucked(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::capsuleCenterDucked, Value);
		}

		void CapsuleCenter(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::capsuleCenter, Value);
		}

		void GravityMultiplier(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::gravityMultiplier, Value);
		}

		void MaxVelocity(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::PlayerWalkMovement::maxVelocity, Value);
		}
	};
}