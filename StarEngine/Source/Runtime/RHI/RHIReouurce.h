#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
enum class RHIResourceType
{

};
class RHIResource
{
public:
    RHIResource(RHIResourceType type);

    virtual ~RHIResource();
public:
	uint32 AddRef() const;


	uint32 Release() const;
	

	uint32 GetRefCount() const;


	bool IsValid() const;

	RHIResourceType GetType() const;

	String GetOwnerName() const;
	void SetOwnerName(const String& name);

private:
//	class FAtomicFlags
//	{
//		static constexpr uint32 MarkedForDeleteBit = 1 << 30;
//		static constexpr uint32 DeletingBit = 1 << 31;
//		static constexpr uint32 NumRefsMask = ~(MarkedForDeleteBit | DeletingBit);
//
//		std::atomic_uint Packed = { 0 };
//
//	public:
//		int32 AddRef(std::memory_order MemoryOrder)
//		{
//			uint32 OldPacked = Packed.fetch_add(1, MemoryOrder);
//			checkf((OldPacked & DeletingBit) == 0, TEXT("Resource is being deleted."));
//			int32  NumRefs = (OldPacked & NumRefsMask) + 1;
//			checkf(NumRefs < NumRefsMask, TEXT("Reference count has overflowed."));
//			return NumRefs;
//		}
//
//		int32 Release(std::memory_order MemoryOrder)
//		{
//			uint32 OldPacked = Packed.fetch_sub(1, MemoryOrder);
//			checkf((OldPacked & DeletingBit) == 0, TEXT("Resource is being deleted."));
//			int32  NumRefs = (OldPacked & NumRefsMask) - 1;
//			checkf(NumRefs >= 0, TEXT("Reference count has underflowed."));
//			return NumRefs;
//		}
//
//		bool MarkForDelete(std::memory_order MemoryOrder)
//		{
//			uint32 OldPacked = Packed.fetch_or(MarkedForDeleteBit, MemoryOrder);
//			check((OldPacked & DeletingBit) == 0);
//			return (OldPacked & MarkedForDeleteBit) != 0;
//		}
//
//		bool UnmarkForDelete(std::memory_order MemoryOrder)
//		{
//			uint32 OldPacked = Packed.fetch_xor(MarkedForDeleteBit, MemoryOrder);
//			check((OldPacked & DeletingBit) == 0);
//			bool  OldMarkedForDelete = (OldPacked & MarkedForDeleteBit) != 0;
//			check(OldMarkedForDelete == true);
//			return OldMarkedForDelete;
//		}
//
//		bool Deleting()
//		{
//			uint32 LocalPacked = Packed.load(std::memory_order_acquire);
//			check((LocalPacked & MarkedForDeleteBit) != 0);
//			check((LocalPacked & DeletingBit) == 0);
//			uint32 NumRefs = LocalPacked & NumRefsMask;
//
//			if (NumRefs == 0) // caches can bring dead objects back to life
//			{
//#if DO_CHECK
//				Packed.fetch_or(DeletingBit, std::memory_order_acquire);
//#endif
//				return true;
//			}
//			else
//			{
//				UnmarkForDelete(std::memory_order_release);
//				return false;
//			}
//		}
//
//		bool IsValid(std::memory_order MemoryOrder)
//		{
//			uint32 LocalPacked = Packed.load(MemoryOrder);
//			return (LocalPacked & MarkedForDeleteBit) == 0 && (LocalPacked & NumRefsMask) != 0;
//		}
//
//		bool IsMarkedForDelete(std::memory_order MemoryOrder)
//		{
//			return (Packed.load(MemoryOrder) & MarkedForDeleteBit) != 0;
//		}
//
//		int32 GetNumRefs(std::memory_order MemoryOrder)
//		{
//			return Packed.load(MemoryOrder) & NumRefsMask;
//		}
//	};
//	mutable FAtomicFlags AtomicFlags;
	const RHIResourceType m_type;
};
}// namespace Star