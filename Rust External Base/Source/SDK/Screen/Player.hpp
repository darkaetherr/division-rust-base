#pragma once

#include "../SDK.h"

#include "../../Dependencies/Window/ImGui/imgui.h"

namespace SDK
{
	namespace Screen
	{
		class Player
		{
		private:
		public:
			Player(SDK::World::Player Player, SDK::Unity::Camera::Matrix ViewMatrix)
			{
				if (!Player.Valid)
				{
					this->Valid = false;
					return;
				}

				if (!SDK::Unity::Camera::WorldToScreen(Player.Upper, &this->Upper, ViewMatrix))
				{
					this->Valid = false;
					return;
				}

				if (!SDK::Unity::Camera::WorldToScreen(Player.Lower, &this->Lower, ViewMatrix))
				{
					this->Valid = false;
					return;
				}
			}

			void Render(ImDrawList* Renderer)
			{
				if (!this->Valid)
				{
					return;
				}

				const Math::Vector2 Size = Math::Vector2((this->Upper.y - this->Lower.y) * 0.40f, this->Upper.y - this->Lower.y);

				Renderer->AddRect(ImVec2(this->Upper.x - Size.x / 2, this->Upper.y), ImVec2(this->Upper.x + Size.x / 2, this->Upper.y - Size.y), ImColor(1.00f, 1.00f, 1.00f, 1.00f));
			}

			Math::Vector2 Upper = Math::Vector2();
			Math::Vector2 Lower = Math::Vector2();

			bool Valid = true;
		};
	}
}