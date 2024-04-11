#pragma once

#include "../../Dependencies/Math/Vector/Vector.hpp"
#include "../../Dependencies/Driver/Driver.h"

class CStorage
{
private:
public:
	class CScreen
	{
	private:
	public:
		Math::Vector2 Center = Math::Vector2();
		Math::Vector2 Size = Math::Vector2();
	};

	std::uint64_t GameAssembly = 0x00;
	std::uint64_t UnityPlayer = 0x00;

	CScreen* Screen = new CScreen();

	bool Setup();
};

inline CStorage* Storage = new CStorage();