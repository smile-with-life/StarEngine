#include"starpch.h"
#include"Test.h"
#include"Runtime/Core/File/File.h"
#include"Runtime/Core/Config/Config.h"
#include"Runtime/OpenGL/Shader.h"
#include"Runtime/Core/Container/List.h"

namespace Star::Test
{
void Test_File()
{
    ByteArray buffer("const");
    String show;
    File file;

    file.Manage("Asset/Test/test.txt");

    std::cout << "文件是否能打开:" << (file.Open(OpenMode::ReadWrite) ? "true" : "false") << std::endl;
    
    std::cout << "创建文件:" << (file.Create() ? "true" : "false") << std::endl;

    std::cout << "文件是否能打开:" << (file.Open(OpenMode::ReadWrite) ? "true" : "false") << std::endl;
    
    std::cout << "向文件中写入内容..." << std::endl;
    
    file.WriteAll(buffer);

    std::cout << "缓冲未刷新的文件大小:" << file.Size() << std::endl;

    file.Flush();
    std::cout << "缓冲刷新后的文件大小:" << file.Size() << std::endl;

    std::cout << "设置文件大小" << file.Resize(0) << std::endl;
    std::cout << "修改后的文件大小:" << file.Size() << std::endl;
    std::cout << "文件完整路径:" << file.GetFilePath() << std::endl;
    std::cout << "文件所在目录:" << file.GetFileDir() << std::endl;
    std::cout << "文件名:" << file.GetFileName() << std::endl;
    std::cout << "文件名主干部分:" << file.GetFileStem() << std::endl;
    std::cout << "文件扩展名:" << file.GetFileEXT() << std::endl;

    std::cout << "关闭文件" << std::endl;
    file.Close();
    
    std::cout << "重新打开文件:" << (file.Open(OpenMode::ReadOnly) ? "true" : "false") << std::endl;

    std::cout << "从文件中读取内容..." << std::endl;
    file.ReadAll(buffer);

    show = buffer;

    std::cout << "文件内容:" << show << std::endl;
   
    std::cout << "关闭文件..." << std::endl;
    file.Close();

    std::cout << "拷贝文件..." << std::endl;
    file.Copy("Asset/Test/testcopy.txt");

    std::cout << "重命名文件..." << std::endl;
    file.Rename("Asset/Test/testreanme.txt");

    std::cout << "检查文件是否存在testreanme.txt:" << File::Exists("Asset/Test/testreanme.txt") << std::endl;
    std::cout << "检查文件是否存在testcopy.txt:" << File::Exists("Asset/Test/testcopy.txt") << std::endl;

    std::cout << "删除文件..." << std::endl;
    file.Remove();

    std::cout << "检查文件是否存在testreanme.txt:" << File::Exists("Asset/Test/testreanme.txt") << std::endl;
    std::cout << "检查文件是否存在testcopy.txt:" << File::Exists("Asset/Test/testcopy.txt") << std::endl;
    
    file.Close();

    file.Manage("Asset/Test/testcopy.txt");

    file.Remove();
    
    file.Close();
    
    
}

void Test_Config()
{
    ConfigFile config;

    config.Load("Asset/Test/config.ini");

    std::cout << config.GetInt("group_2", "asd") << std::endl;
    std::cout << config.GetInt("group_2", "qwe") << std::endl;

    config.AddSection("group_1");
    config.AddItem("group_1", "asd", "2");
    config.AddItem("group_1", "qwe", "1");
    config.AddSection("group_2");
    config.AddItem("group_2", "asd", "2");
    config.AddItem("group_2", "qwe", "1");
    config.Save();
}
}