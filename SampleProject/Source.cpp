#define ENTRY_POINT extern "C" __declspec(dllexport) void

#include <iostream>

ENTRY_POINT Start()
{
	
}

ENTRY_POINT Update()
{
	std::cout << "Im Updating" << std::endl;
}

ENTRY_POINT Exit()
{
	std::cout << "Im Exiting" << std::endl;
}
