#pragma once

namespace Star {
class IApplication
{
public:
    virtual ~IApplication() = default;
    virtual int run() = 0;
};
}//namespace Star
