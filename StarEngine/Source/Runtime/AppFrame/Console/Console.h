#pragma once

#include "Runtime/Core/Core.h"

namespace Star
{

class Console
{ 
public:
    Console() = default;
    ~Console() = default;

    virtual void Show();

    virtual void Hide();

    virtual bool isShow();
public:
    static Console* Create();
};

}// namespace Star