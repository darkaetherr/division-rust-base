#pragma once

#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <vector>

class CDriver
{
private:
	HANDLE Handle = 0x00;
	DWORD Id = 0x00;
public:
	bool Write(const std::uint64_t& Address, void* Buffer, const std::size_t& Size);
	bool Read(const std::uint64_t& Address, void* Buffer, const std::size_t& Size);
	std::uint64_t GetModuleBase(const char* Name);

	template<typename Type>
	bool Write(const std::uint64_t& Address, const Type& Data)
	{
		return this->Write(Address, (void*)(&Data), sizeof(Data));
	}

	template<typename Type>
	Type Read(const std::uint64_t& Address)
	{
		Type Data = Type();

		this->Read(Address, (void*)(&Data), sizeof(Data));

		return Data;
	}

	template<typename Type>
	Type ReadChain(const std::uint64_t& Address, std::vector<std::uint64_t> Offsets)
	{
		// Initilizing Value
		std::uint64_t Value = Address;

		// Reading The Offsets Into The Value
		for (int i = 0; i < Offsets.size() - 1; i++)
		{
			const std::uint64_t& Offset = Offsets[i];

			Value = this->Read<std::uint64_t>(Value + Offset);
		}

		// Returning The Value + Final Offset
		return this->Read<Type>(Value + Offsets[Offsets.size() - 1]);
	}

	std::string ReadWString(const std::uint64_t& Address)
	{
		if (!Address)
			return "";

		std::uint64_t NewAddress = this->Read<std::uint64_t>(Address);
		if (!NewAddress)
			return "";

		int Length = this->Read<int>(NewAddress + 0x10) * sizeof(wchar_t);
		if (!Length)
			return "";

		// Array Of Characters To Read Into
		wchar_t* Buffer = (wchar_t*)malloc(Length);

		this->Read(NewAddress + 0x14, Buffer, Length);

		std::wstring TempString = std::wstring(Buffer, Length / 2);

		free(Buffer);

		return std::string(TempString.begin(), TempString.end());
	}

	const char* ReadString(const std::uint64_t& Address)
	{
		std::uint64_t NewAddress = this->Read<std::uint64_t>(Address);

		// Array Of Characters To Read Into
		std::unique_ptr<char[]> Buffer(new char[128]);

		// Reading The Characters Into The Array
		this->Read(NewAddress, Buffer.get(), 128);

		// Returning Array Of Characters As A String
		return Buffer.get();
	}

	bool Attach(const char* Name);
};

inline CDriver* Driver = new CDriver();