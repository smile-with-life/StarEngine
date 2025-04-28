#include "starpch.h"
#include "Time.h"

namespace Star::Time
{
void Delay(Seconds second)
{
    auto size = second.Count();
    std::this_thread::sleep_for(std::chrono::seconds(size));
}

void Delay(Milliseconds ms)
{
    auto size = ms.Count();
    std::this_thread::sleep_for(std::chrono::seconds(size));
}

void Delay(Microseconds us)
{
    auto start = SteadyClock::Now();

    while (1)
    {
        auto end = SteadyClock::Now();
        auto duration = ConvertType<Microseconds>(end - start);
        if (duration >= us)
        {
            break;
        }
    }
}
}// namespace Star::Time