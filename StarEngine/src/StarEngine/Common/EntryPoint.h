#pragma once

namespace Star {
    extern StarEngineLoop EngineLoop;
}// namespace Star

#ifdef STAR_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
    Star::EngineLoop.PreInit();
    Star::EngineLoop.Init();
    while (!Star::EngineLoop.isRequestingExit())
    {
        Star::EngineLoop.Tick();
    }
    Star::EngineLoop.Exit();
    return 0;
}
#endif // STAR_PLATFORM_WINDOWS
