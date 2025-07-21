#pragma once
#include "Core/Core.h"
#include "Core/String/String.h"
#include "Core/Thread/Mutex.h"
#include <random>

namespace Star
{
class GUID
{
public:
	// 默认构造函数
	GUID();

	// 析构函数
	~GUID() = default;

	// 拷贝构造函数
	GUID(const GUID& other) = default;

	// 拷贝赋值函数
	GUID& operator=(const GUID& other) = default;

	// 移动构造函数
	GUID(GUID&& other) = default;

	// 移动赋值函数
	GUID& operator=(GUID&& other) = default;

	// 构造函数 
	GUID(uint64 guid);
public:
	operator uint64() const;

	friend bool operator==(const GUID& left, const GUID& right);
	  
	friend bool operator!=(const GUID& left, const GUID& right);

	friend bool operator>(const GUID& left, const GUID& right);

	friend bool operator>=(const GUID& left, const GUID& right);

	friend bool operator<(const GUID& left, const GUID& right);

	friend bool operator<=(const GUID& left, const GUID& right);
private:
	
	uint64 m_guid;

	static Mutex s_mutex;

	static std::mt19937_64 s_randomEngine;

	static std::uniform_int_distribution<uint64_t> s_dist;
};
}// namespace Star