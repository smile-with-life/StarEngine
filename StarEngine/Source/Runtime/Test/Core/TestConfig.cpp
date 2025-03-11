#include"starpch.h"
#include"Runtime/Test/Test.h"

#include"Runtime/Core/File/File.h"
#include"Runtime/Core/Config/Config.h"

namespace Star::Test
{
void Test_Config()
{
    std::cout << "**********Config单元测试**********" << std::endl;
    ConfigFile config;
    config.Load("Asset/Test/config.ini");
    Assert(config.GetInt("group_1", "int") == 1);
    Assert(config.GetFloat("group_1", "float") == 1.0);
    Assert(config.GetDouble("group_1", "double") == 1.0);
    Assert(config.GetString("group_1", "string") == "asd");
    Assert(config.GetBool("group_1", "bool") == true);
    Assert(config.GetInt("group_2", "int") == 2);
    Assert(config.GetFloat("group_2", "float") == 2.0);
    Assert(config.GetDouble("group_2", "double") == 2.0);
    Assert(config.GetString("group_2", "string") == "qwe");
    Assert(config.GetBool("group_2", "bool") == false);
    config.Save();

    Assert(File::Exists("Asset/Test/newconfig.ini") == false);
    config.Load("Asset/Test/newconfig.ini");
    config.AddSection("new_1");
    config.AddItem("new_1", "cui", "1");
    config.AddItem("new_1", "wen", "2");
    config.AddItem("new_1", "qian", "3");
    Assert(config.GetInt("new_1", "cui") == 1);
    Assert(config.GetInt("new_1", "wen") == 2);
    Assert(config.GetInt("new_1", "qian") == 3);
    config.AddSection("new_2");
    Assert(config.Num() == 2);
    config.RemoveSection("new_2");
    Assert(config.Num() == 1);
    config.RemoveItem("new_1","qian");
    Assert(config.Visit("new_1").Num() == 2);
    config.Save();
    Assert(File::Exists("Asset/Test/newconfig.ini") == true);
    File::Remove("Asset/Test/newconfig.ini");
    Assert(File::Exists("Asset/Test/newconfig.ini") == false);
}
}// namespace Star::Test