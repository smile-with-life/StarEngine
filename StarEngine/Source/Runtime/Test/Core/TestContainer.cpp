#include"starpch.h"
#include"Runtime/Test/Test.h"

#include"Runtime/Core/Container/Array.h"
namespace Star::Test
{
void Test_Array_1()
{
    using TestObject = Test_Standard_Class;
    // 默认构造
    Array<TestObject> a1;
    Assert(a1.Size() == 0 && a1.Capacity() == 0);

    // 列表构造
    Array<TestObject> a2{ TestObject(), TestObject(2) };
    Assert(a2.Front().Value() == 1);
    Assert(a2.Back().Value() == 2);

    // 拷贝构造
    Array<TestObject> a3(a2);
    Assert(a3.Front().Value() == 1);
    Assert(a3.Back().Value() == 2);

    // 移动构造
    Array<TestObject> a4(std::move(a2));
    Assert(a4.Front().Value() == 1);
    Assert(a4.Back().Value() == 2);

    // 拷贝赋值
    Array<TestObject> a5;
    a5 = a4;
    Assert(a5.Front().Value() == 1);
    Assert(a5.Back().Value() == 2);

    // 移动赋值
    Array<TestObject> a6;
    a6 = std::move(a5);
    Assert(a6.Front().Value() == 1);
    Assert(a6.Back().Value() == 2);

    // 列表赋值
    Array<TestObject> a7 = { TestObject(), TestObject(2) };
    Assert(a7.Front().Value() == 1);
    Assert(a7.Back().Value() == 2);

    // 迭代器构造
    Array<TestObject> a8(a7.begin(), a7.end());
    Assert(a8.Front().Value() == 1);
    Assert(a8.Back().Value() == 2);

    // 构造函数 Array(int64 count)
    Array<TestObject> a9(5);
    Assert(a9.Size() == 5);
    for (const auto& iter : a9)
    {
        Assert(iter.Value() == 1);
    }

    // 构造函数 Array(int64 count, const Type& value)
    Array<TestObject> a10(5, TestObject(2));
    Assert(a10.Size() == 5);
    for (const auto& iter : a10)
    {
        Assert(iter.Value() == 2);
    }

}

void Test_Array()
{
    std::cout << "**********Array单元测试**********" << std::endl;
    Test_Array_1();
}
}// namespace Star::Test