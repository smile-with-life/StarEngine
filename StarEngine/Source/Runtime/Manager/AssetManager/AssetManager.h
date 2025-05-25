#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

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
    bool LoadAsset(const String& path);
};
}// namespace Star