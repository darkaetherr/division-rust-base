#pragma once

#include <Windows.h>
#include <functional>

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"

#include "DirectX/DirectX.h"

class CWindow
{
private:
	static LRESULT CALLBACK Callback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam);
	void Input(const HWND& Target);
public:
	Device* DirectX = 0x00;
	HWND Handle = 0x00;

	bool Status = true;
	bool Active = true;
	bool Valid = false;

	CWindow();
	
	int Render(const HWND& Game, std::function<void()> Menu, std::function<void()> Draw);
};

inline CWindow* Window = new CWindow();