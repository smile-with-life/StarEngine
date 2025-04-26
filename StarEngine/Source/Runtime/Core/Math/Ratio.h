#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Concept/Concept.h"
#include<ratio>

namespace Star
{
template<Concept::IntegralType Num, Concept::IntegralType Den>
class Ratio
{
public:
private:
    std::ratio<1,1> 
};
}