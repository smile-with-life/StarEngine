#include "starpch.h"
#include "Config.h"
#include <iosfwd>
#include "Runtime/Core/File/File.h"
#include <format>
namespace Star
{
ConfigFile::~ConfigFile()
{
    Save();
}

bool ConfigFile::Load(const String& path_)
{
    Clear();

    m_fileName = path_;
    File file(path_);

    // 文件不存在则创建
    file.Create();

    if (file.Open(OpenMode::ReadOnly))
    {
        // @实现 ini文件语法检查器

        ByteArray buffer;
        String line;
        String header;
        String key;
        String value;

        while (!file.IsEOF())
        {
            file.ReadLine(buffer);
            line = buffer;
            line.Trim();
            if (line.IsEmpty() || line[0] == ';' || line[0] == '#')
            {
                continue;
            }

            // 判断是否为节的头           
            if (line.FrontChar() == '[' && line.BackChar() == ']')
            {
                header = line.Match('[',']');
                m_sectionOrder.PushBack(header);// 记录配置节的顺序
                continue;
            }

            // 解析键值对
            key = line.Section('=', 0).Trim();
            value = line.Section('=', 1).Trim();
            if (value.FrontChar() == '\"' && value.BackChar() == '\"')
            {
                value = value.Match('\"', '\"');
            }
            m_sections[header].AddItem(key, value);
            m_sections[header].m_itemOrder.PushBack(key);// 记录配置项的顺序    
        }

        return true;
    }

    return false;
}

bool ConfigFile::Save()
{
    return SaveAs(m_fileName);
}

bool ConfigFile::SaveAs(const String& path_)
{
    File file(path_);
    ByteArray buffer;
    String config;

    if (file.Open(OpenMode::ReadWrite)) 
    {
        for (const auto& header : m_sectionOrder)
        {    
            const auto& section = m_sections[header];
            config.Append(std::format("[{}]\n", header.ToStdString()));
            for (const auto& key : section.m_itemOrder) 
            {
                const auto& value = section.m_items[key];
                config.Append(std::format("{} = {}\n", key.ToStdString(), value.ToStdString()));
            }
            config.Append('\n');
        }
        buffer.Add(&config[0], config.Size());
        return file.WriteAll(buffer);
    }
    return false;
}

void ConfigFile::AddSection(const Name& section)
{
    m_sections[section];
    m_sectionOrder.PushBack(section);
}

void ConfigFile::AddItem(const Name& section, const Name& key, const String& value)
{
    if (!m_sections.Contains(section))
    {
        m_sectionOrder.PushBack(section);
    }
    m_sections[section].AddItem(key, value);
}

void ConfigFile::RemoveSection(const Name& section)
{
    if (m_sections.Erase(section))
    {
        const auto iter = m_sectionOrder.iter_find(section);
        m_sectionOrder.Erase(iter);
    }
}

void ConfigFile::RemoveItem(const Name& section, const Name& key)
{
    m_sections.At(section).RemoveItem(key);
}

bool ConfigFile::IsEmpty() const
{
    return m_sections.Size();
}

void ConfigFile::Clear()
{
    m_sections.Clear();
    m_sectionOrder.Clear();
}

bool ConfigFile::Contains(const String& section) const
{
    return m_sections.Contains(section);
}

int64 ConfigFile::Num() const
{
    return m_sections.Size();
}

ConfigSection& ConfigFile::Visit(const String& section)
{
    return m_sections.At(section);
}

String ConfigFile::GetString(const String& section, const String& key) const
{
    return m_sections.At(section).GetValue(key);
}

int64 ConfigFile::GetInt(const String& section, const String& key) const
{
    return m_sections.At(section).GetValue(key).ToInt32();
}

int64 ConfigFile::GetInt64(const String& section, const String& key) const
{
    return m_sections.At(section).GetValue(key).ToInt64();
}

float ConfigFile::GetFloat(const String& section, const String& key) const
{
    return m_sections.At(section).GetValue(key).ToFloat();
}

double ConfigFile::GetDouble(const String& section, const String& key) const
{
    return m_sections.At(section).GetValue(key).ToDouble();
}

bool ConfigFile::GetBool(const String& section, const String& key) const
{
    return m_sections.At(section).GetValue(key).ToBool();
}

void ConfigFile::SetString(const String& section, const String& key, const String value)
{
    m_sections.At(section).SetValue(key, value);
}

void ConfigFile::SetInt(const String& section, const String& key, int value)
{
    m_sections.At(section).SetValue(key, String::FromInt32(value));
}

void ConfigFile::SetInt64(const String& section, const String& key, int64 value)
{
    m_sections.At(section).SetValue(key, String::FromInt64(value));
}

void ConfigFile::SetFloat(const String& section, const String& key, float value)
{
    m_sections.At(section).SetValue(key, String::FromFloat(value));
}

void ConfigFile::SetDouble(const String& section, const String& key, double value)
{
    m_sections.At(section).SetValue(key, String::FromDouble(value));
}

void ConfigFile::SetBool(const String& section, const String& key, bool value)
{
    m_sections.At(section).SetValue(key, String::FromBool(value));
}
}// namespace Star