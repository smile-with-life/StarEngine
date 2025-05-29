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
private:

	const RHIResourceType m_type;
};
}// namespace Star