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
	: Console()
	, m_console(0)
{

}

WindowsConsole::~WindowsConsole()
{
	Hide();
}

void WindowsConsole::Show()
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONIN$", "r", stdin);
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	m_console = GetStdHandle(STD_OUTPUT_HANDLE);
}

void WindowsConsole::Hide()
{
	m_console = NULL;
	FreeConsole();
}

bool WindowsConsole::isShow()
{
	return m_console != NULL;
}

}// namespace Star