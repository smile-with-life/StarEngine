#include "starpch.h"
#include "WindowsApplication.h"

namespace Star {
WindowsApplication::WindowsApplication()
    : m_quit(false)
{

}

WindowsApplication::~WindowsApplication()
{

}

int WindowsApplication::run()
{
    while (!m_quit)
    {
        std::cout << "Hello Engine!" << std::endl;
        break;
    }
    return 0;
}

}// namespace Star