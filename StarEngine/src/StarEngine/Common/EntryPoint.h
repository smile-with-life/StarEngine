#pragma once

#ifdef STAR_PLATFORM_WINDOWS

namespace Star {
IApplication* createApplication()
{
    return new WindowsApplication();
}
}// namespace Star 

int main(int argc, char** argv)
{
    auto app = Star::createApplication();
    int ret = app->run();
    delete app;
    return ret;
}
#endif // STAR_PLATFORM_WINDOWS
