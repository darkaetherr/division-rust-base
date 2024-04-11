#pragma once

#include "../../Dependencies.h"

namespace Math
{
	// Utils
	static double ToRad(double degree)
	{
		double pi = 3.14159265359;
		return (degree * (pi / 180));
	}

	// Classes
	class Vector2
	{
	public:
		float x, y;

		Vector2() { };

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2 operator+(const Vector2& Input)
		{
			return Vector2{ x + Input.x, y + Input.y };
		}

		Vector2 operator-(const Vector2& Input)
		{
			return Vector2{ x - Input.x, y - Input.y };
		}

		Vector2 operator*(const Vector2& Input)
		{
			return Vector2{ x * Input.x, y * Input.y };
		}

		Vector2 operator/(const float& Input)
		{
			return Vector2{ x / Input, y / Input };
		}


		Vector2 operator*(const float& Input)
		{
			return Vector2{ x * Input, y * Input };
		}


		bool IsValid()
		{
			return x && y;
		}

		float Length()
		{
			return std::sqrt((x * x) + (y * y));
		}

		float Distance(Vector2 To)
		{
			return std::sqrt(std::pow(To.x - x, 2.f) + std::pow(To.y - y, 2.f));
		}

		Vector2 Normalize()
		{
			if (y <= -180.f) y += 360.f;
			else if (y > 180.f) y -= 360.f;

			if (x > 90.f) x -= 180.f;
			else if (x <= -90.f) x += 180.f;

			return { x,y };
		}

		void Clamp()
		{
			x = std::clamp(x, -89.0f, 89.0f);
			y = std::clamp(y, -179.0f, 179.0f);
		}
	};

	class Vector3
	{
	public:
		float x, y, z;

		Vector3()
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
		}

		Vector3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3 operator+(const Vector3& Input)
		{
			return Vector3{ x + Input.x, y + Input.y, z + Input.z };
		}

		Vector3 operator-(const Vector3& Input)
		{
			return Vector3{ x - Input.x, y - Input.y, z - Input.z };
		}

		Vector3 operator/(float Input)
		{
			return Vector3{ x / Input, y / Input, z / Input };
		}

		Vector3 operator*(float Input)
		{
			return Vector3{ x * Input, y * Input, z * Input };
		}

		Vector3& operator+=(const Vector3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		Vector3& operator-=(const Vector3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		Vector3& operator/=(float Input)
		{
			x /= Input;
			y /= Input;
			z /= Input;

			return *this;
		}

		Vector3& operator*=(float Input)
		{
			x *= Input;
			y *= Input;
			z *= Input;

			return *this;
		}

		bool operator==(const Vector3& Input)
		{
			return x == Input.x && y == Input.y && z == Input.z;
		}

		void MakeAbsolute()
		{
			x = std::abs(x);
			y = std::abs(y);
			z = std::abs(z);
		}

		float LengthSqr() const
		{
			return (x * x) + (y * y) + (z * z);
		}

		float Length() const
		{
			return (float)std::sqrt(LengthSqr());
		}

		float Length2D() const
		{
			return (float)sqrt((x * x) + (y * y));
		}

		float Magnitude() { return (float)sqrt(x * x + y * y + z * z); }
		float Magnitude2D() { return (float)sqrt(x * x + z * z); }

		Vector3 Normalize() const
		{
			Vector3 tis(this->x, this->y, this->z);
			float num = Vector3(this->x, this->y, this->z).Magnitude();
			if (num > 1E-05f)
			{
				tis.x /= num;
				tis.y /= num;
				tis.z /= num;
			}
			else
				tis = { 0, 0, 0 };


			return { tis.x,tis.y,tis.z };
		}


		Vector3 Cross(Vector3 rhs) const
		{
			return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
		}

		float Dot(Vector3 Input) const
		{
			return (x * Input.x + y * Input.y + z * Input.z);
		}

		float Distance(Vector3 Input)
		{
			return (*this - Input).Length();
		}

		float DistanceSqr(Vector3 Input)
		{
			Vector3 Difference = { x - Input.x, y - Input.y, z - Input.z };
			return Difference.x * Difference.x + Difference.y * Difference.y + Difference.z * Difference.z;
		}

		float Distance2D(Vector3 Input)
		{
			return (*this - Input).Length2D();
		}

		void Clamp()
		{
			std::clamp(x, -89.f, 89.f);
			std::clamp(y, -180.f, 180.f);
			z = 0.f;
		}

		bool IsValid() const
		{
			return !(x == 0.f && y == 0.f && z == 0.f) || (x == -1.f && y == -1.f && z == -1.f);
		}
	};


	class Vector4
	{
	public:
		float x, y, z, w;

		Vector4()
		{
			this->x = 0.f;
			this->y = 0.f;
			this->z = 0.f;
			this->w = 0.f;
		}

		Vector4(float x, float y, float z, float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vector4 operator+(const Vector4& input);
		Vector4 operator-(const Vector4& input);
		Vector4 operator/(float input);
		Vector4 operator*(Vector4 input)
		{
			return Vector4{
			x * input.x,
			y * input.y,
			z * input.z,
			w * input.w };
		}

		Vector4& operator-=(const Vector4& v);
		Vector4& operator/=(float input);
		Vector4& operator*=(float input);
		bool operator==(const Vector4& input);
		float LengthSqr();
		float Length();
		float Length2D();
		float Dot(Vector4 Input);
		float Distance(Vector4 Input);
		float Distance2D(Vector4 Input);
		void Clamp();
		bool IsValid();

		Vector3 operator* (Vector3 point)
		{
			float num = this->x * 2.f;
			float num2 = this->y * 2.f;
			float num3 = this->z * 2.f;
			float num4 = this->x * num;
			float num5 = this->y * num2;
			float num6 = this->z * num3;
			float num7 = this->x * num2;
			float num8 = this->x * num3;
			float num9 = this->y * num3;
			float num10 = this->w * num;
			float num11 = this->w * num2;
			float num12 = this->w * num3;
			Vector3 result;
			result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
			result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
			result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
			return result;
		}

		static Vector3 QuanternionMult(Vector3 Offset, Vector4 Quanternion)
		{
			float num1 = Quanternion.x * 2.f;
			float num2 = Quanternion.y * 2.f;
			float num3 = Quanternion.z * 2.f;
			float num4 = Quanternion.x * num1;
			float num5 = Quanternion.y * num2;
			float num6 = Quanternion.z * num3;
			float num7 = Quanternion.x * num2;
			float num8 = Quanternion.x * num3;
			float num9 = Quanternion.y * num3;
			float num10 = Quanternion.w * num1;
			float num11 = Quanternion.w * num2;
			float num12 = Quanternion.w * num3;

			Vector3 result = Vector3();

			result.x = (1.f - (num5 + num6)) * Offset.x + (num7 - num12) * Offset.y + (num8 + num11) * Offset.z;
			result.y = (num7 + num12) * Offset.x + (1.f - (num4 + num6)) * Offset.y + (num9 - num10) * Offset.z;
			result.z = (num8 - num11) * Offset.x + (num9 + num10) * Offset.y + (1.f - (num4 + num5)) * Offset.z;

			return result;
		}


		static float Magnitude(Vector3 vector) { return (float)sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z); }

		static Vector3 Normalize(Vector3 value)
		{
			float mag = Magnitude(value);
			if (mag > 0.00001f)
				return { value.x / mag, value.y / mag, value.z / mag };
			else
				return Vector3(0, 0, 0);
		}

		static Vector3 Cross(Vector3 lhs, Vector3 rhs)
		{
			return {
				lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.x * rhs.y - lhs.y * rhs.x };
		}

		static Vector4 QuaternionLookRotation(Vector3 forward, Vector3 up)
		{
			Vector3 vector = Normalize(forward);
			Vector3 vector2 = Normalize(Cross(up, vector));
			Vector3 vector3 = Cross(vector, vector2);
			float m00 = vector2.x;
			float m01 = vector2.y;
			float m02 = vector2.z;
			float m10 = vector3.x;
			float m11 = vector3.y;
			float m12 = vector3.z;
			float m20 = vector.x;
			float m21 = vector.y;
			float m22 = vector.z;

			float num8 = (m00 + m11) + m22;
			Vector4 quaternion = {};
			if (num8 > 0.f)
			{
				float num = (float)sqrt(num8 + 1.f);
				quaternion.w = num * 0.5f;
				num = 0.5f / num;
				quaternion.x = (m12 - m21) * num;
				quaternion.y = (m20 - m02) * num;
				quaternion.z = (m01 - m10) * num;
				return quaternion;
			}
			if ((m00 >= m11) && (m00 >= m22))
			{
				float num7 = (float)sqrt(((1.f + m00) - m11) - m22);
				float num4 = 0.5f / num7;
				quaternion.x = 0.5f * num7;
				quaternion.y = (m01 + m10) * num4;
				quaternion.z = (m02 + m20) * num4;
				quaternion.w = (m12 - m21) * num4;
				return quaternion;
			}
			if (m11 > m22)
			{
				float num6 = (float)sqrt(((1.f + m11) - m00) - m22);
				float num3 = 0.5f / num6;
				quaternion.x = (m10 + m01) * num3;
				quaternion.y = 0.5f * num6;
				quaternion.z = (m21 + m12) * num3;
				quaternion.w = (m20 - m02) * num3;
				return quaternion;
			}
			float num5 = (float)sqrt(((1.f + m22) - m00) - m11);
			float num2 = 0.5f / num5;
			quaternion.x = (m20 + m02) * num2;
			quaternion.y = (m21 + m12) * num2;
			quaternion.z = 0.5f * num5;
			quaternion.w = (m01 - m10) * num2;
			return quaternion;
		}

		static Vector4 QuaternionFromEulerRad(Vector3 euler)
		{
			float yaw = euler.x;
			float pitch = euler.y;
			float roll = euler.z;
			float rollOver2 = roll * 0.5f;
			float sinRollOver2 = (float)sin((float)rollOver2);
			float cosRollOver2 = (float)cos((float)rollOver2);
			float pitchOver2 = pitch * 0.5f;
			float sinPitchOver2 = (float)sin((float)pitchOver2);
			float cosPitchOver2 = (float)cos((float)pitchOver2);
			float yawOver2 = yaw * 0.5f;
			float sinYawOver2 = (float)sin((float)yawOver2);
			float cosYawOver2 = (float)cos((float)yawOver2);
			Vector4 result;
			result.x = cosYawOver2 * cosPitchOver2 * cosRollOver2 + sinYawOver2 * sinPitchOver2 * sinRollOver2;
			result.y = cosYawOver2 * cosPitchOver2 * sinRollOver2 - sinYawOver2 * sinPitchOver2 * cosRollOver2;
			result.z = cosYawOver2 * sinPitchOver2 * cosRollOver2 + sinYawOver2 * cosPitchOver2 * sinRollOver2;
			result.w = sinYawOver2 * cosPitchOver2 * cosRollOver2 - cosYawOver2 * sinPitchOver2 * sinRollOver2;
			return result;
		}

		static Vector4 Euler(float x, float y, float z)
		{
			return Vector4::QuaternionFromEulerRad(Vector3(x, y, z) * 0.0174532924f);
		}

		static Vector4 ToQuanternion(Vector3 Angles)
		{
			double heading = ToRad(Angles.x);
			double attitude = ToRad(Angles.y);
			double bank = ToRad(0x00);

			double c1 = cos(heading / 2);
			double s1 = sin(heading / 2);
			double c2 = cos(attitude / 2);
			double s2 = sin(attitude / 2);
			double c3 = cos(bank / 2);
			double s3 = sin(bank / 2);
			double c1c2 = c1 * c2;
			double s1s2 = s1 * s2;

			Vector4 Quat{};
			Quat.w = c1c2 * c3 - s1s2 * s3;
			Quat.x = c1c2 * s3 + s1s2 * c3;
			Quat.y = s1 * c2 * c3 + c1 * s2 * s3;
			Quat.z = c1 * s2 * c3 - s1 * c2 * s3;

			return { Quat.y, Quat.z, (Quat.x * -1), Quat.w };
		}
	};
	typedef Vector4 Quaternion;
}