#include "starpch.h"
#include "Sence.h"

#include "Runtime/Core/File/File.h"
#include "Runtime/Core/Json/Json.h"

namespace Star
{
void Sence::Init()
{
    for (auto& entity : m_entities)
    {
        entity.Init();
    }
}

void Sence::Tick()
{
    for (auto& entity : m_entities)
    {     
        entity.Tick();
    }
}

void Sence::Exit()
{
    for (auto& entity : m_entities)
    {
        entity.Exit();
    }
}

void Sence::Load(const String& senceUrl)
{
    File file(senceUrl);
    file.Open(OpenMode::ReadOnly);
    ByteBuffer buffer;
    file.ReadAll(buffer);
    Json json = Json::Parse(buffer);

    m_name = json["scenes"][0]["name"];

    auto sence = json["scenes"][0];
    m_name = sence["name"];
    auto nodes = sence["nodes"].Get<JsonArray>();

    for (auto& item : nodes)
    {
        int32 index = item.Get<int32>();
        json["nodes"];
    }
}
}// namespace Star