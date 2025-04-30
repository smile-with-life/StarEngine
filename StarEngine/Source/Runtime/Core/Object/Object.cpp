#include "starpch.h"
#include "Object.h"

namespace Star
{
Object::Object()
    : m_guid()
{

}

Object::~Object()
{

}

GUID Object::GetGUID() const
{
    return m_guid;
}

}// namespace Star