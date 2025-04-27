#include "starpch.h"
#include "WindowsConsole.h"

namespace Star
{	
/* static*/
Console* Console::Create()
{
	return new WindowsConsole();
}
/* member */
WindowsConsole::WindowsConsole()
	: m_console(0)
{

}

WindowsConsole::~WindowsConsole()
{
	m_console = NULL;
	FreeConsole();
}

void WindowsConsole::Init()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONIN$", "r", stdin);
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	m_console = GetStdHandle(STD_OUTPUT_HANDLE);
}

void WindowsConsole::Tick()
{
	
}

void WindowsConsole::Exit()
{
	
}

}// namespace Star