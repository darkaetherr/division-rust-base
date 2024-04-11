#pragma once

#include <dwmapi.h> 
#include <dwrite.h>

#pragma comment(lib, "Dwmapi.lib") 
#pragma comment(lib, "Dwrite")

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib") 
#pragma comment(lib, "d3dx9.lib") 

class Device
{
private:
	D3DPRESENT_PARAMETERS Parameters;
public:
	IDirect3DDevice9* Pointer;

	bool Valid = false;

	Device(const HWND& Handle);

	void Begin();
	void End();
};

