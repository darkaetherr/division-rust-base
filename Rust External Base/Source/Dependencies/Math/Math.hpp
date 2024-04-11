#pragma once

#include "Vector/Vector.hpp"

#include <Windows.h>
#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))

namespace Math
{
	static Math::Vector3 CalculateAngles(Math::Vector3 source, Math::Vector3 destination)
	{
		Math::Vector3 dir = source - destination;

		Math::Vector2 Value = Math::Vector2{ RAD2DEG(asin(dir.y / dir.Length())), RAD2DEG(-atan2(dir.x, -dir.z)) }.Normalize();

		return { Value.x, Value.y, 0.00f };
	}

	static Math::Vector3 AnglesMult(Math::Vector2 Angles, Math::Vector3 Value)
	{
		float X = Value.x * sin((Angles.x * M_PI / 180.f));
		float Y = Value.y * sin((Angles.y * M_PI / 180.f));
		float Z = Value.z * cos((Angles.x * M_PI / 180.f));

		return { X,Y,Z };
	}

	static float NormalizeAngle(float Angle)
	{
		while (Angle > 360) Angle -= 360;
		while (Angle < 0) Angle += 360;
		return Angle;
	}

	static Math::Vector2 RotatatePoint(Math::Vector2 PointToRotate, Math::Vector2 CenterPoint, float Angle)
	{
		float rad = ((NormalizeAngle(Angle)) * static_cast<float>((M_PI / 180.f)));
		float s = -sin(rad);
		float c = cos(rad);
		float xnew = PointToRotate.x * c - PointToRotate.y * s;
		float znew = PointToRotate.x * s + PointToRotate.y * c;
		PointToRotate.x -= CenterPoint.x;
		PointToRotate.y -= CenterPoint.y;
		PointToRotate.x = xnew + CenterPoint.x;
		PointToRotate.y = znew + CenterPoint.y;
		return PointToRotate;
	}

	static void VectorAngles(Math::Vector3& forward, Math::Vector3& angles)
	{
		if (forward.y == 0.0f && forward.x == 0.0f)
		{
			angles.x = (forward.z > 0.0f) ? 270.0f : 90.0f;
			angles.y = 0.0f;
		}
		else
		{
			angles.x = atan2(-forward.z, forward.Length()) * -180.f / static_cast<float>(M_PI);
			angles.y = atan2(forward.y, forward.x) * 180.f / static_cast<float>(M_PI);

			if (angles.y > 90)
				angles.y -= 180;
			else if (angles.y < 90)
				angles.y += 180;
			else if (angles.y == 90)
				angles.y = 0;
		}

		angles.z = 0.0f;
	}

	static Math::Vector3 Smooth(Math::Vector3 Angles, const Math::Vector3& Original, const float& Smoothing)
	{
		Angles -= Original;
		Angles /= Smoothing;
		Angles += Original;

		return Angles;
	}

	static double deg2rad(double deg) {
		return deg * M_PI / 180.0;
	}

	static void RotateTriangle(std::vector<Math::Vector2>& points, float rotation)
	{
		const auto points_center = Math::Vector2(points.at(0) + points.at(1) + points.at(2)) / 3;

		for (auto& point : points)
		{
			point = point - points_center;

			const auto temp_x = point.x;
			const auto temp_y = point.y;

			const auto theta = deg2rad(rotation);
			const auto c = cosf(theta);
			const auto s = sinf(theta);

			point.x = temp_x * c - temp_y * s;
			point.y = temp_x * s + temp_y * c;

			point + point + points_center;
		}
	}
}