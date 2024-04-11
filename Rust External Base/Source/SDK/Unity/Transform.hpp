#pragma once

#include "../SDK.h"

#include <intrin.h>

namespace SDK
{
	namespace Unity
	{
		class Transform
		{
		private:

			struct AccessReadOnly
			{
				std::uint64_t TransformData;
			};

			struct Data
			{
				std::uint64_t TransformArray;
				std::uint64_t TransformIndecies;
			};

			struct Matrix34
			{
				Math::Vector4 Vec1{};
				Math::Vector4 Vec2{};
				Math::Vector4 Vec3{};
			};

		public:
			std::uint64_t Address()
			{
				return (std::uint64_t)(this);
			}

			Math::Vector3 Position()
			{
				SDK::Unity::Transform::AccessReadOnly TransformAccessReadOnly = Driver->Read<SDK::Unity::Transform::AccessReadOnly>(this->Address() + 0x38);
				SDK::Unity::Transform::Data TransformData = Driver->Read<SDK::Unity::Transform::Data>(TransformAccessReadOnly.TransformData + 0x18);

				unsigned int Index = Driver->Read<unsigned int>(this->Address() + 0x40);

				const __m128 MultiplyVector1 = { -2.000, 2.000, -2.000, 0.000 };
				const __m128 MultiplyVector2 = { 2.000, -2.000, -2.000, 0.000 };
				const __m128 MultiplyVector3 = { -2.000, -2.000, 2.000, 0.000 };

				__m128 Result{};

				int TransformIndex = Driver->Read<int>(TransformData.TransformIndecies + 0x4 * Index);
				int Safe = 0;

				Result = Driver->Read<__m128>(TransformData.TransformArray + 0x30 * Index);

				while (TransformIndex >= 0 && Safe++ < 200)
				{
					SDK::Unity::Transform::Matrix34 Matrix = Driver->Read<SDK::Unity::Transform::Matrix34>(TransformData.TransformArray + 0x30 * TransformIndex);

					__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.Vec2), 0x00));	// xxxx
					__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.Vec2), 0x55));	// yyyy
					__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.Vec2), 0x8E));	// zwxy
					__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.Vec2), 0xDB));	// wzyw
					__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.Vec2), 0xAA));	// zzzz
					__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.Vec2), 0x71));	// yxwy
					__m128 tmp7 = _mm_mul_ps(*(__m128*)(&Matrix.Vec3), Result);

					Result = _mm_add_ps(_mm_add_ps(
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(xxxx, MultiplyVector2), zwxy),
									_mm_mul_ps(_mm_mul_ps(yyyy, MultiplyVector3), wzyw)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(zzzz, MultiplyVector3), wzyw),
									_mm_mul_ps(_mm_mul_ps(xxxx, MultiplyVector1), yxwy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(yyyy, MultiplyVector1), yxwy),
									_mm_mul_ps(_mm_mul_ps(zzzz, MultiplyVector2), zwxy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
							tmp7)), *(__m128*)(&Matrix.Vec1));

					TransformIndex = Driver->Read<int>(TransformData.TransformIndecies + 0x4 * TransformIndex);
				}

				return Math::Vector3(Result.m128_f32[0], Result.m128_f32[1], Result.m128_f32[2]);
			}
		};
	}
}