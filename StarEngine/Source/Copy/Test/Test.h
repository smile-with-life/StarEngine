#pragma once

#ifdef STAR_TEST
    #define TESTING_INIT_BEGIN() Star::Test::UnitTestingInitBegin()
    #define TESTING_INIT_END() Star::Test::UnitTestingInitEnd()
    #define TESTING_TICK_BEGIN() Star::Test::UnitTestingTickBegin()
    #define TESTING_TICK_END() Star::Test::UnitTestingTickEnd()
    #define TESTING_EXIT_BEGIN() Star::Test::UnitTestingExitBegin()
    #define TESTING_EXIT_END() Star::Test::UnitTestingExitEnd()
#else
    #define TESTING_INIT_BEGIN() 
    #define TESTING_INIT_END()
    #define TESTING_TICK_BEGIN()
    #define TESTING_TICK_END()
    #define TESTING_EXIT_BEGIN()
    #define TESTING_EXIT_END()
#endif


namespace Star::Test
{
// 引擎初始化开始前进行
void UnitTestingInitBegin();

// 引擎初始化完成后进行
void UnitTestingInitEnd();

// 引擎帧开始前进行
void UnitTestingTickBegin();

// 引擎帧完成后进行
void UnitTestingTickEnd();

// 引擎退出开始前进行
void UnitTestingExitBegin();

// 引擎退出完成后进行
void UnitTestingExitEnd();

void Test_Array();
void Test_File();
void Test_Config();
void Test_RAII();
void Test_Json();

// 标准测试类
class Test_Standard_Class
{
public:
    Test_Standard_Class() = default;
    ~Test_Standard_Class() = default;

    Test_Standard_Class(int n)
        : m_num(n)
    {

    }

    Test_Standard_Class(const Test_Standard_Class& other) = default;
    Test_Standard_Class& operator=(const Test_Standard_Class& other) = default;

    Test_Standard_Class(Test_Standard_Class&& other) noexcept = default;
    Test_Standard_Class& operator=(Test_Standard_Class&& other) noexcept = default;
public:
    int Value() const
    {
        return m_num;
    }

    int SetValue(int value)
    {
        m_num = value;
    }
public:
    friend bool operator==(const Test_Standard_Class& left, const Test_Standard_Class& right)
    {
        return left.m_num == right.m_num;
    }

    friend bool operator!=(const Test_Standard_Class& left, const Test_Standard_Class& right)
    {
        return left.m_num != right.m_num;
    }

    friend bool operator>(const Test_Standard_Class& left, const Test_Standard_Class& right)
    {
        return left.m_num > right.m_num;
    }

    friend bool operator>=(const Test_Standard_Class& left, const Test_Standard_Class& right)
    {
        return left.m_num >= right.m_num;
    }

    friend bool operator<(const Test_Standard_Class& left, const Test_Standard_Class& right)
    {
        return left.m_num < right.m_num;
    }

    friend bool operator<=(const Test_Standard_Class& left, const Test_Standard_Class& right)
    {
        return left.m_num <= right.m_num;
    }
private:
    int m_num = 1;
};
}// namespace Star::Test