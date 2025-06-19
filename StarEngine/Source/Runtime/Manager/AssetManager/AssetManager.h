#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"
#include "Runtime/Core/File/File.h"
#include "Runtime/Core/Json/Json.h"

namespace Star
{
class AssetManager
{
public:
    AssetManager() = default;
public:
    void Init();

    void Tick();

    void Exit();
public:
    template<class AssetType>
    bool LoadAsset(const String& url, AssetType& asset)
    {
        File file(url);
        file.Open(OpenMode::ReadOnly);
        ByteBuffer buffer;
        file.ReadAll(buffer);
        Json json = Json::Parse(buffer);
    }
};
}// namespace Star