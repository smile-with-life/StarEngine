#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/GUID/GUID.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
class Object
{
public:
    Object();

    virtual ~Object();

    Object(const Object& other) = default;

    Object& operator=(const Object& other) = default;

    Object(Object&& other) = default;

    Object& operator=(Object&& other) = default;
public:
    GUID GetGUID() const;
protected:
    GUID m_guid;
};
}// namespace Star