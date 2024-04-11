#include "Window.h"

#include <iostream>
#include <thread>

LRESULT CWindow::Callback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0x00);
		return 0x00;
	}

	return DefWindowProcW(Window, Message, WParam, LParam);
}

void CWindow::Input(const HWND& Target)
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		if (GetAsyncKeyState(VK_INSERT) & 0x1)
		{
			this->Status = !this->Status;
		}

		// Getting Io Of ImGui
		ImGuiIO& Io = ImGui::GetIO();

		// Getting Mouse Position
		POINT CursorPos;
		GetCursorPos(&CursorPos);

		// Fixing Mouse Position
		Io.MousePos.x = CursorPos.x;
		Io.MousePos.y = CursorPos.y;

		// Checking If The User Is Clicking Whilst Tabbed Into The Game
		if (GetAsyncKeyState(VK_LBUTTON) && (GetForegroundWindow() == Target))
		{
			Io.MouseClickedPos[0].x = Io.MousePos.x;
			Io.MouseClickedPos[0].y = Io.MousePos.y;

			Io.MouseDown[0] = true;
			Io.MouseClicked[0] = true;
			Io.WantSetMousePos = true;

			continue;
		}

		Io.MouseDown[0] = false;
		Io.MouseClicked[0] = false;
	}
}

CWindow::CWindow()
{
	WNDCLASSEXA WindowClass =
	{
		sizeof(WNDCLASSEXA),
		CS_HREDRAW | CS_VREDRAW,
		CWindow::Callback,
		0x00, 0x00,
		GetModuleHandleA(0x00),
		LoadIconA(0x00, IDI_APPLICATION),
		LoadCursorA(0x00, IDC_ARROW),
		(HBRUSH)(CreateSolidBrush(RGB(0x00, 0x00, 0x00))),
		0x00,
		"CrosshairX-x64",
		0x00
	};

	if (!RegisterClassExA(&WindowClass))
	{
		return;
	}

	this->Handle = CreateWindowExA
	(
		WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
		WindowClass.lpszClassName,
		"CrosshairX",
		WS_POPUP,
		0x00,
		0x00,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		0x00,
		0x00,
		WindowClass.hInstance,
		0x00
	);

	if (!this->Handle)
	{
		return;
	}

	MARGINS Margins = { -1 };
	DwmExtendFrameIntoClientArea(this->Handle, &Margins);

	SetLayeredWindowAttributes(this->Handle, 0x00, 1.0f, LWA_ALPHA);
	SetLayeredWindowAttributes(this->Handle, 0x00, RGB(22, 22, 22), LWA_COLORKEY);

	this->DirectX = new Device(this->Handle);

	if (!this->DirectX)
	{
		return;
	}

	ShowWindow(this->Handle, SW_SHOW);
	UpdateWindow(this->Handle);

	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(this->Handle);
	ImGui_ImplDX9_Init(this->DirectX->Pointer);

	ImGui::GetIO().IniFilename = 0x00;

	this->Valid = true;
}

int CWindow::Render(const HWND& Game, std::function<void()> Menu, std::function<void()> Draw)
{
	std::thread([&]() { this->Input(Game); }).detach();
	using namespace ImGui;

	while (this->Active)
	{
		this->DirectX->Begin();
		
		if (GetForegroundWindow() == Game)
		{
			SetWindowLong(this->Handle, -20, GetWindowLong(this->Handle, -20) & ~WS_EX_LAYERED);

			if (this->Status)
			{
				Menu();
			}

			Draw();
		}

		SetWindowLong(this->Handle, -20, GetWindowLong(this->Handle, -20) | WS_EX_LAYERED);

		this->DirectX->End();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0x00;
}