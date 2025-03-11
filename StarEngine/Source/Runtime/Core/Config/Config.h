#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"
#include "Runtime/Core/Container/Map.h"
namespace Star
{
// 前向声明
class ConfigFile;
class ConfigValue
{
public:
    enum class ValueType : uint8
    {
        IntType,
        FloatType,
        DoubleType, 
        StringType,
        BoolType,
        Vec2Type,
        Vec3Type,
        Vec4Type,
    };
public:
    // 默认构造函数
    ConfigValue() = default;

    // 析构函数
    ~ConfigValue() = default;

private:
    // 配置值
    String m_value;

    // 配置值的类型
    ValueType m_type;
};

// 配置节（由多个配置项组成,每个配置项由键值对组成）
class ConfigSection
{
public:
    using iterator = Map<Name, String>::iterator;
    using const_iterator = Map<Name, String>::const_iterator;
    using reverse_iterator = Map<Name, String>::reverse_iterator;
    using const_reverse_iterator = Map<Name, String>::const_reverse_iterator;
public:
    ConfigSection() = default;

    ~ConfigSection() = default;

    // 配置项的数量
    int64 Num() const
    {
        return m_items.Size();
    }

    // 返回配置项的值，未找到时抛出异常
    String GetValue(const Name& key) const
    {
        return m_items.At(key);
    }

    // 设置配置项的值，未找到时抛出异常
    void SetValue(const Name& key, const String& value)
    {
        m_items.At(key) = value;
    }

    // 添加配置项，未找到时添加相应项
    void AddItem(const Name& key, const String& value)
    {
        if (!m_items.Contains(key))
        {
            m_itemOrder.PushBack(key);
        }
        m_items[key] = value;
    }

    // 删除配置项
    void RemoveItem(const Name& key)
    {
        if (m_items.Erase(key))
        {
            const auto iter = m_itemOrder.iter_find(key);
            m_itemOrder.Erase(iter);
        }
    }
public:
    [[nodiscard]] iterator begin() noexcept
    {
        return m_items.begin();
    }

    [[nodiscard]] const_iterator begin() const noexcept
    {
        return m_items.begin();
    }

    [[nodiscard]] iterator end() noexcept
    {
        return m_items.end();
    }

    [[nodiscard]] const_iterator end() const noexcept
    {
        return m_items.end();
    }

    [[nodiscard]] const_iterator cbegin() const noexcept
    {
        return m_items.cbegin();
    }

    [[nodiscard]] const_iterator cend() const noexcept
    {
        return m_items.cend();
    }

    [[nodiscard]] reverse_iterator rbegin() noexcept
    {
        return m_items.rbegin();
    }

    [[nodiscard]] const_reverse_iterator rbegin() const noexcept
    {
        return m_items.rbegin();
    }

    [[nodiscard]] reverse_iterator rend() noexcept
    {
        return m_items.rend();
    }

    [[nodiscard]] const_reverse_iterator rend() const noexcept
    {
        return m_items.rend();
    }

    [[nodiscard]] const_reverse_iterator crbegin() const noexcept
    {
        return m_items.crbegin();
    }

    [[nodiscard]] const_reverse_iterator crend() const noexcept
    {
        return m_items.crend();
    }
private:
    // 友元
    friend ConfigFile;
    
    // 配置项映射表
    Map<Name, String> m_items;

    // 配置项顺序数组
    Array<Name> m_itemOrder;
};

// 配置文件（由多个配置节组成）
class ConfigFile
{ 
public:
    using iterator = Map<Name, ConfigSection>::iterator;
    using const_iterator = Map<Name, ConfigSection>::const_iterator;
    using reverse_iterator = Map<Name, ConfigSection>::reverse_iterator;
    using const_reverse_iterator = Map<Name, ConfigSection>::const_reverse_iterator;
public:
    // 默认构造函数
    ConfigFile() = default;

    // 析构函数
    ~ConfigFile();

    // 读取配置文件
    bool Load(const String& path);

    // 写入配置文件
    bool Save();

    // 另存为
    bool SaveAs(const String& path);

    // 添加配置节，未找到时添加相应项
    void AddSection(const Name& section);
    
    // 添加配置项，未找到时添加相应项
    void AddItem(const Name& section, const Name& key, const String& value);

    // 移除配置节
    void RemoveSection(const Name& section);

    // 移除配置项
    void RemoveItem(const Name& section, const Name& key);

    // 检查配置文件是否为空
    bool IsEmpty() const;

    // 清空配置文件中的所有节
    void Clear();

    // 是否包含指定的配置节
    bool Contains(const String& section) const;

    // 返回节的数量
    int64 Num() const;

    // 访问指定节
    ConfigSection& Visit(const String& section);

    // 获取配置值(String)
    String GetString(const String& section, const String& key) const;

    // 获取配置值(int)
    int64 GetInt(const String& section, const String& key) const;

    // 获取配置值(int64)
    int64 GetInt64(const String& section, const String& key) const;

    // 获取配置值(float)
    float GetFloat(const String& section, const String& key) const;

    // 获取配置值(double)
    double GetDouble(const String& section, const String& key) const;

    // 获取配置值(bool)，未找到时抛出异常
    bool GetBool(const String& section, const String& key) const;

    // 设置配置值(String)，未找到时抛出异常
    void SetString(const String& section, const String& key, const String value);

    // 设置配置值(int)，未找到时抛出异常
    void SetInt(const String& section, const String& key, int value);

    // 设置配置值(int64)，未找到时抛出异常
    void SetInt64(const String& section, const String& key, int64 value);

    // 设置配置值(float)，未找到时抛出异常
    void SetFloat(const String& section, const String& key, float value);

    // 设置配置值(double)，未找到时抛出异常
    void SetDouble(const String& section, const String& key, double value);

    // 设置配置值(bool)，未找到时抛出异常
    void SetBool(const String& section, const String& key, bool value);  
public:
    [[nodiscard]] iterator begin() noexcept
    {
        return m_sections.begin();
    }

    [[nodiscard]] const_iterator begin() const noexcept
    {
        return m_sections.begin();
    }

    [[nodiscard]] iterator end() noexcept
    {
        return m_sections.end();
    }

    [[nodiscard]] const_iterator end() const noexcept
    {
        return m_sections.end();
    }

    [[nodiscard]] const_iterator cbegin() const noexcept
    {
        return m_sections.cbegin();
    }

    [[nodiscard]] const_iterator cend() const noexcept
    {
        return m_sections.cend();
    }

    [[nodiscard]] reverse_iterator rbegin() noexcept
    {
        return m_sections.rbegin();
    }

    [[nodiscard]] const_reverse_iterator rbegin() const noexcept
    {
        return m_sections.rbegin();
    }

    [[nodiscard]] reverse_iterator rend() noexcept
    {
        return m_sections.rend();
    }

    [[nodiscard]] const_reverse_iterator rend() const noexcept
    {
        return m_sections.rend();
    }

    [[nodiscard]] const_reverse_iterator crbegin() const noexcept
    {
        return m_sections.crbegin();
    }

    [[nodiscard]] const_reverse_iterator crend() const noexcept
    {
        return m_sections.crend();
    }
private:
    // 配置节映射列表
    Map<Name, ConfigSection> m_sections;

    // 配置节的顺序数组
    Array<Name> m_sectionOrder;

    // 配置文件
    String m_fileName;
};
}




