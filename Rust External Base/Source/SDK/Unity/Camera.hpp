#pragma once

#include "../SDK.h"

namespace SDK
{
	namespace Unity
	{
		class Camera
		{
		private:
		public:
			struct Matrix
			{
				union
				{
					struct
					{
						float _11, _12, _13, _14;
						float _21, _22, _23, _24;
						float _31, _32, _33, _34;
						float _41, _42, _43, _44;
					};
					float m[4][4];
				};
			};

			static SDK::Unity::Camera* Instance()
			{
				return Driver->ReadChain<SDK::Unity::Camera*>(Storage->GameAssembly, { Offset::MainCamera, 0xB8, 0x00, 0x10 });
			}

			std::uint64_t Address()
			{
				return (std::uint64_t)(this);
			}

			SDK::Unity::Camera::Matrix ViewMatrix()
			{
				return Driver->Read<SDK::Unity::Camera::Matrix>(this->Address() + 0x2E4);
			}

			Math::Vector3 Position()
			{
				return Driver->Read<Math::Vector3>(this->Address() + 0x42C);
			}

			static bool WorldToScreen(const Math::Vector3& World, Math::Vector2* ScreenOut, const SDK::Unity::Camera::Matrix& ViewMatrix)
			{
				// Transposing Vector
				Math::Vector3 TransposeVector{ ViewMatrix._14, ViewMatrix._24, ViewMatrix._34 };
				Math::Vector3 RightVector{ ViewMatrix._11, ViewMatrix._21, ViewMatrix._31 };
				Math::Vector3 UpVector{ ViewMatrix._12, ViewMatrix._22, ViewMatrix._32 };

				// Getting Values
				float W = TransposeVector.Dot(World) + ViewMatrix._44;
				float X = RightVector.Dot(World) + ViewMatrix._41;
				float Y = UpVector.Dot(World) + ViewMatrix._42;

				// Setting Screen Position
				if (ScreenOut)
				{
					*ScreenOut = Math::Vector2(Storage->Screen->Center.x * (1.00f + X / W), Storage->Screen->Center.y * (1 - Y / W));
				}
				else
				{
					return W > 0.098f;
				}

				// Validating Screen Position
				return ScreenOut->IsValid() && W > 0.098f;
			}
		};
	}
}