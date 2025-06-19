#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"
#include "Runtime/Core/Container/Array.h"
#include "Runtime/Core/Memory/RAII.h"
#include "Runtime/Render/Sence/Sence.h"
#include "Runtime/Core/File/File.h"
#include "Runtime/Core/Json/Json.h"
#include "Runtime/Core/Container/Map.h"

namespace Star
{
struct World
{
    void Load(const String& worldUrl)
    {
        File file(worldUrl);
        file.Open(OpenMode::ReadOnly);
        ByteBuffer buffer;
        file.ReadAll(buffer);
        Json world = Json::Parse(buffer);
        m_name = world["Name"].Get<String>();

        auto arr = world["SenceUrls"].Get<JsonArray>();
        for (auto& item : arr)
        {
            m_senceUrls.Append(item.Get<String>());
        }

        m_defaultSenceUrl = world["DefaultSenceUrl"];
    }
    // 世界名称
    String m_name;
    Array<String> m_senceUrls;
    String m_defaultSenceUrl;
};
}// namespace Star