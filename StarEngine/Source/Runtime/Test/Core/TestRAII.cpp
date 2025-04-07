#include "starpch.h"
#include "Runtime/Test/Test.h"

#include "Runtime/Core/Memory/RAII.h"

namespace Star::Test
{

void Test_RAII()
{
    auto ptr = MakeScope<Test_Standard_Class>(3);
}
}// namespace Star::Test