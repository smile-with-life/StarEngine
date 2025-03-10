#pragma once
#include"Runtime/Core/Core.h"

namespace Star
{
template<class T>
class DefaultAllocator
{
public:
	// 默认构造函数
	constexpr DefaultAllocator() = default;
	
	// 析构函数
	constexpr ~DefaultAllocator() = default;

	// 解分配
	constexpr void Deallocate(T* const ptr, const size_t count)
	{
		m_alloc.deallocate(ptr, count);
	}

	// 分配
	[[nodiscard]] constexpr T* Allocate(const size_t count)
	{
		return m_alloc.allocate(count);
	}
private:
	[[no_unique_address]] std::allocator<T> m_alloc;
};
}// namespace Star