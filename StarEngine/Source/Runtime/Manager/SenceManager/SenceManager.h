#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"
#include "Runtime/Core/Container/Map.h"
#include "Runtime/Core/GUID/GUID.h"
#include "Runtime/Core/File/File.h"
#include "Runtime/Core/Json/Json.h"
#include "Runtime/Core/Memory/RAII.h"
#include "Runtime/Render/Sence/Sence.h"

namespace Star
{
struct World
{
    String name;
    Array<String> senceUrls;
    String defaultSenceUrl;

    void Load(const String& worldUrl)
    {
        File file(worldUrl);
        file.Open(OpenMode::ReadOnly);
        ByteBuffer buffer;
        file.ReadAll(buffer);
        Json world = Json::Parse(buffer);
        this->name = world["Name"].Get<String>();

        auto arr = world["SenceUrls"].Get<JsonArray>();
        for (auto& item : arr)
        {
            this->senceUrls.Append(item.Get<String>());
        }

        this->defaultSenceUrl = world["DefaultSenceUrl"];
    }
};
class SenceManager
{
public:
    SenceManager() = default;
public:
    void Init();

    void Tick();

    void Exit();

    void LoadWorld(const String& worldUrl);

    void LoadSence(const String& senceUrl);
private:
    World m_world;

    SharedPtr<Sence> m_activeSence;
};
}// namespace Star