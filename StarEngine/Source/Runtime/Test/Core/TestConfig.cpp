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
    std::cout << "###新建一个 config.ini 文件###" << std::endl;
    Assert(File::Exists("Asset/Test/config.ini") == false);
    config.Load("Asset/Test/config.ini");// 当文件不存在时会新建文件
    Assert(File::Exists("Asset/Test/config.ini") == true);
    Assert(config.Num() == 0);
    std::cout << "###向配置文件中添加节和键值对###" << std::endl;
    config.AddSection("group_1");
    config.AddItem("group_1", "int", "1");
    config.AddItem("group_1", "float", "1.0");
    config.AddItem("group_1", "double", "1.0");
    config.AddItem("group_1", "string", "asd");
    config.AddItem("group_1", "bool", "true");
    config.AddSection("group_2");
    config.AddItem("group_2", "int", "2");
    config.AddItem("group_2", "float", "2.0");
    config.AddItem("group_2", "double", "2.0");
    config.AddItem("group_2", "string", "qwe");
    config.AddItem("group_2", "bool", "false");
    std::cout << "配置节的数量：" << config.Num() <<std::endl;
    std::cout << "###检查配置文件的键值对###" << std::endl;
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
    std::cout << "###移除 config.ini 文件###" << std::endl;
    File::Remove("Asset/Test/config.ini");
    Assert(File::Exists("Asset/Test/newconfig.ini") == false);
    
    Assert(File::Exists("Asset/Test/newconfig.ini") == false);
    std::cout << "###新建一个 newconfig.ini 文件###" << std::endl;
    config.Load("Asset/Test/newconfig.ini");
    std::cout << "###测试config的成员函数###" << std::endl;
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
    std::cout << "###移除 newconfig.ini 文件###" << std::endl;
    File::Remove("Asset/Test/newconfig.ini");
    Assert(File::Exists("Asset/Test/newconfig.ini") == false);
}
}// namespace Star::Test