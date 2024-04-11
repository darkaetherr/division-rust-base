#include "Driver.h"

#include <TlHelp32.h>

bool CDriver::Write(const std::uint64_t& Address, void* Buffer, const std::size_t& Size)
{
    return WriteProcessMemory(this->Handle, (void*)(Address), Buffer, Size, nullptr);
}

bool CDriver::Read(const std::uint64_t& Address, void* Buffer, const std::size_t& Size)
{
    return ReadProcessMemory(this->Handle, (void*)(Address), Buffer, Size, nullptr);
}

std::uint64_t CDriver::GetModuleBase(const char* Name)
{
    HANDLE Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->Id);

    if (Snapshot == INVALID_HANDLE_VALUE)
    {
        return 0x00;
    }

    MODULEENTRY32 Entry;
    Entry.dwSize = sizeof(Entry);

    if (!Module32First(Snapshot, &Entry))
    {
        return 0x00;
    }

    do
    {
        if (!std::strcmp(Entry.szModule, Name))
        {
            CloseHandle(Snapshot);
            return (std::uint64_t)(Entry.modBaseAddr);
        }

    } while (Module32Next(Snapshot, &Entry));

    CloseHandle(Snapshot);

    return 0x00;
}

bool CDriver::Attach(const char* Name)
{
	PROCESSENTRY32 Entry;
	Entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (!Process32First(Snapshot, &Entry))
	{
		return false;
	}

	while (Process32Next(Snapshot, &Entry))
	{
		if (!std::strcmp(Entry.szExeFile, Name))
		{
			this->Handle = OpenProcess(PROCESS_ALL_ACCESS, false, Entry.th32ProcessID);
			this->Id = Entry.th32ProcessID;
		}
	}

	CloseHandle(Snapshot);

    return true;
}
