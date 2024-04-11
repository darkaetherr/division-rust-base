#include "Storage.h"

bool CStorage::Setup()
{
    this->Screen->Size = Math::Vector2(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    this->Screen->Center = this->Screen->Size / 2;

    if (!this->Screen->Size.IsValid())
    {
        return false;
    }

    this->GameAssembly = Driver->GetModuleBase("GameAssembly.dll");

    if (!this->GameAssembly)
    {
        return false;
    }

    this->UnityPlayer = Driver->GetModuleBase("UnityPlayer.dll");

    if (!this->UnityPlayer)
    {
        return false;
    }

    return true;
}
