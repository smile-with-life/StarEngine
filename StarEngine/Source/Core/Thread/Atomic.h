#pragma once
#include "Core/Core.h"

namespace Star
{
enum class MemoryOrder
{
	// 宽松定序, 不会引起重排序
	Relaxed,

	// 顺序一致
	SequentiallyConsistent,
};
template<class T>
class Atomic
{

};
}// namespace Star
