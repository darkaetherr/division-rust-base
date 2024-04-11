#pragma once

#include "../SDK.h"

namespace SDK
{
	namespace World
	{
		class Player
		{
		private:
		public:
			Player(SDK::BasePlayer* Player)
			{
				SDK::PlayerModel* PlayerModel = Player->PlayerModel();

				if (!Player || !PlayerModel)
				{
					this->Valid = false;
					return;
				}

				if (PlayerModel->IsLocalPlayer())
				{
					this->Valid = false;
					return;
				}

				if (Player->Lifestate() != SDK::Enum::LifeState::Alive)
				{
					this->Valid = false;
					return;
				}

				if (Player->HasFlag(SDK::Enum::BasePlayerFlags::Sleeping))
				{
					this->Valid = false;
					return;
				}

				SDK::Model* Model = Player->Model();

				if (!Model)
				{
					this->Valid = false;
					return;
				}

				this->Upper = Model->Bone(SDK::Enum::BoneId::Head)->Position() + Math::Vector3(0.00f, 0.30f, 0.00f);
				this->Lower = PlayerModel->Position() - Math::Vector3(0.00f, 0.30f, 0.00f);
			}

			Math::Vector3 Upper = Math::Vector3();
			Math::Vector3 Lower = Math::Vector3();

			bool Valid = true;
		};
	}
}