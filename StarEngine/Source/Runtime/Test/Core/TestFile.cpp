#include"starpch.h"
#include"Runtime/Test/Test.h"

#include"Runtime/Core/File/File.h"

namespace Star::Test
{
void Test_File()
{   
    std::cout << "**********File单元测试**********" << std::endl;
    Assert(File::Exists("Asset/Test/test.txt") == false);
    File file("Asset/Test/test.txt");
    Assert(file.Size() == -1);

    {
        // 文件是否存在不影响文件路径的解析，只要文件路径格式正确
        std::cout << "###文件路径解析...###" << std::endl; 
        String filePath = file.GetFilePath();
        String fileDir = file.GetFileDir();
        String fileName = file.GetFileName();
        String fileStem = file.GetFileStem();
        String fileEXT = file.GetFileEXT();
        std::cout << "文件完整路径:" << filePath << std::endl;
        std::cout << "文件所在目录:" << fileDir << std::endl;
        std::cout << "文件名:" << fileName << std::endl;
        std::cout << "文件名主干部分:" << fileStem << std::endl;
        std::cout << "文件扩展名:" << fileEXT << std::endl;
        std::cout << File::AbsolutePath("Asset/Test/test.txt") << std::endl;
        Assert(filePath == File::AbsolutePath("Asset/Test/test.txt"));
        Assert(fileDir == File::FileDir("Asset/Test/test.txt"));
        Assert(fileName == File::FileName("Asset/Test/test.txt"));
        Assert(fileStem == File::FileStem("Asset/Test/test.txt"));
        Assert(fileEXT == File::FileEXT("Asset/Test/test.txt"));
    }

    std::cout << "###文件创建...###" << std::endl;
    Assert(file.Create() == true);
    Assert(File::Exists("Asset/Test/test.txt") == true);
    Assert(file.Open(OpenMode::ReadWrite) == true);
    std::cout << "###文件写入...###" << std::endl;
    ByteArray buffer("测试文件");
    Assert(file.WriteAll(buffer) == true);
    std::cout << "缓冲未刷新的文件大小:" << file.Size() << std::endl;
    file.Flush();
    std::cout << "缓冲刷新后的文件大小:" << file.Size() << std::endl;
    std::cout << "###文件关闭...###" << std::endl;
    file.Close();

    std::cout << "###重新打开文件...###" << std::endl;
    Assert(file.Open(OpenMode::ReadOnly) == true);
    std::cout << "###文件读出...###" << std::endl;
    file.ReadAll(buffer);
    String show;
    show = buffer;
    std::cout << "文件内容:" << show << std::endl;
    std::cout << "###文件关闭...###" << std::endl;
    file.Close();

    std::cout << "###创建文件夹...###" << std::endl;
    File::CreateDir("NewDir");
    std::cout << "###文件拷贝...###" << std::endl;
    Assert(File::FileSize("Asset/Test/test.txt") > 0);
    file.Copy("Asset/Test/NewDir/testcopy.txt");
    Assert(File::Exists("Asset/Test/NewDir/testcopy.txt") == true); 
    Assert(File::FileSize("Asset/Test/NewDir/testcopy.txt") > 0);

    std::cout << "###文件重命名...###" << std::endl;
    file.Rename("Asset/Test/NewDir/testrename.txt");
    Assert(File::Exists("Asset/Test/NewDir/testrename.txt") == true);

    std::cout << "###修改文件大小...###" << std::endl;
    file.Resize(0);
    Assert(file.Size() == 0);

    std::cout << "###文件删除...###" << std::endl;
    File::Remove("Asset/Test/NewDir");
    Assert(File::Exists("Asset/Test/NewDir/testrename.txt") == false);
    Assert(File::Exists("Asset/Test/NewDir/testcopy.txt") == false);
}
}// namespace Star::Test