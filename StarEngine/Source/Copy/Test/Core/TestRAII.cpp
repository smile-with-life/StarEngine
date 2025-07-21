#include "starpch.h"
#include "Runtime/Test/Test.h"

#include "Runtime/Core/Memory/RAII.h"

namespace Star::Test
{

void Test_RAII()
{
    using Class = Test_Standard_Class;

    ScopePtr<Class> ptr1;
    Assert(ptr1.IsNull());
 
    auto ptr2 = MakeScope<Class>(42);
    Assert(!ptr2.IsNull());
    Assert(*ptr2 == 42);

    ScopePtr<Class> ptr3 = MakeScope<Class>(10);
    ScopePtr<Class> ptr4 = std::move(ptr3);
    Assert(ptr3.IsNull());
    Assert(*ptr4 == 10);

    ScopePtr<Class> ptr5 = MakeScope<Class>(20);
    Class* new_ptr = new Class(30);
    ptr5.Reset(new_ptr);
    Assert(*ptr5 == 30);
    Assert(ptr5.RawPtr() == new_ptr);

    ScopePtr<Class> ptr6 = MakeScope<Class>(50);
    ScopePtr<Class> ptr7 = MakeScope<Class>(60);
    ptr6.Swap(ptr7);
    Assert(*ptr6 == 60);
    Assert(*ptr7 == 50);

    ScopePtr<Class> ptr8 = MakeScope<Class>(70);
    ptr8.Delete();
    Assert(ptr8.IsNull());
    std::cout << "应当 delete 7 次" << std::endl;
}
}// namespace Star::Test