#pragma once

namespace Star {

class IRuntimeModule
{
public:
    virtual ~IRuntimeModule() = default;

    virtual int startUp() = 0;
    virtual void shutDown() = 0;
    virtual void tick() = 0;
};
}//namespace Star