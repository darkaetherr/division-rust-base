#include "DirectX.h"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"

Device::Device(const HWND& Handle)
{
	IDirect3D9* Object = Direct3DCreate9(D3D_SDK_VERSION);

	if (!Object)
	{
		return;
	}

	this->Parameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE ;

	this->Parameters.FullScreen_RefreshRateInHz = 0;
	this->Parameters.hDeviceWindow = Handle;
	this->Parameters.Windowed = TRUE;

	this->Parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	this->Parameters.BackBufferFormat = D3DFMT_A8R8G8B8;

	this->Parameters.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	this->Parameters.EnableAutoDepthStencil = TRUE;
	this->Parameters.AutoDepthStencilFormat = D3DFMT_D16;

	HRESULT Result = Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Handle, D3DCREATE_HARDWARE_VERTEXPROCESSING, &this->Parameters, &this->Pointer);

	if (Result < 0x00)
	{
		return;
	}

	this->Valid = true;
}

void Device::Begin()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	
	ImGui::NewFrame();
	this->Pointer->BeginScene();
}

void Device::End()
{
	ImGui::EndFrame();

	this->Pointer->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(0, 0, 0, 0), 0.0f, 0);

	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	this->Pointer->EndScene();
	this->Pointer->Present(NULL, NULL, NULL, NULL);
}
