#pragma once

#include "../SDK.h"

namespace SDK
{
	class BaseProjectile : public SDK::AttackEntity
	{
	private:
	public:
		std::uint64_t Address()
		{
			return (std::uint64_t)(this);
		}

		SDK::Unity::List* CreatedProjectiles()
		{
			return Driver->Read<SDK::Unity::List*>(this->Address() + Offset::BaseProjectile::createdProjectiles);
		}

		SDK::RecoilProperties* RecoilProperties()
		{
			SDK::RecoilProperties* Original = Driver->Read<SDK::RecoilProperties*>(this->Address() + Offset::BaseProjectile::recoil);

			if (!Original)
			{
				return nullptr;
			}

			SDK::RecoilProperties* Override = Original->Override();

			if (Override)
			{
				return Override;
			}

			return Original;
		}
		
		float VelocityScale()
		{
			return Driver->Read<float>(this->Address() + Offset::BaseProjectile::projectileVelocityScale);
		}

		void VelocityScale(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::projectileVelocityScale, Value);
		}

		void SightAimConeOffset(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::sightAimConeOffset, Value);
		}

		void SightAimConeScale(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::sightAimConeScale, Value);
		}

		void HipAimConeOffset(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::hipAimConeOffset, Value);
		}

		void HipAimConeScale(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::hipAimConeScale, Value);
		}

		void HipAimCone(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::hipAimCone, Value);
		}

		void StancePenaltyScale(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::stancePenaltyScale, Value);
		}

		void StancePenalty(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::stancePenalty, Value);
		}

		void AimConePenaltyMax(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::aimConePenaltyMax, Value);
		}

		void AimConePenalty(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::aimconePenalty, Value);
		}

		void AimCone(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::aimCone, Value);
		}

		void AimSwaySpeed(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::aimconePenalty, Value);
		}

		void AimSway(float Value)
		{
			Driver->Write<float>(this->Address() + Offset::BaseProjectile::aimCone, Value);
		}

		void Automatic(bool Value)
		{
			Driver->Write<bool>(this->Address() + Offset::BaseProjectile::automatic, Value);
		}

		bool Automatic()
		{
			return Driver->Read<bool>(this->Address() + Offset::BaseProjectile::automatic);
		}
	};
}