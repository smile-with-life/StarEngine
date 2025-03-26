#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
class GUID
{
public:
	enum Version
	{

	};
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
	// 转为字符串
	String ToString() const;

	// 返回 GUID 的版本信息，版本决定了 GUID 的生成方式
	GUID::Version Version();
public:
	// 从字符串解析GUID
	static GUID FromString(const String& str);
public:
	operator uint64() const;

	bool operator==(const GUID& other);

	bool operator!=(const GUID& other);

	bool operator>(const GUID& other);

	bool operator>=(const GUID& other);

	bool operator<(const GUID& other);

	bool operator<=(const GUID& other);
private:
	uint64 m_guid;
};
}// namespace Star