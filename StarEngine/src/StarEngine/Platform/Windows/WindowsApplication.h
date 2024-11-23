#pragma once

#include "StarEngine/Interface/IApplication.h"

namespace Star {
class WindowsApplication : public IApplication
{
public:
    WindowsApplication();
    virtual ~WindowsApplication();
  
    virtual int run() override;
private:
    bool m_quit;
};





}// namespace Star