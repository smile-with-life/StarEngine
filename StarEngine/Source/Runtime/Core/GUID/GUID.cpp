#include "starpch.h"
#include "GUID.h"


namespace Star
{
Mutex GUID::s_mutex{};

std::mt19937_64 GUID::s_randomEngine{};

std::uniform_int_distribution<uint64_t> GUID::s_dist{};
/* member */
GUID::GUID()
{
    MutexLock<Mutex> lock(s_mutex);
    m_guid = s_dist(s_randomEngine);
}

GUID::GUID(uint64 guid)
    : m_guid(guid)
{

}

GUID::operator uint64() const
{
    return m_guid;
}

bool operator==(const GUID& left, const GUID& right)
{
    return left.m_guid == right.m_guid;
}

bool operator!=(const GUID& left, const GUID& right)
{
    return left.m_guid != right.m_guid;
}

bool operator>(const GUID& left, const GUID& right)
{
    return left.m_guid > right.m_guid;
}

bool operator>=(const GUID& left, const GUID& right)
{
    return left.m_guid >= right.m_guid;
}

bool operator<(const GUID& left, const GUID& right)
{
    return left.m_guid < right.m_guid;
}

bool operator<=(const GUID& left, const GUID& right)
{
    return left.m_guid <= right.m_guid;
}

}// namespace Star
