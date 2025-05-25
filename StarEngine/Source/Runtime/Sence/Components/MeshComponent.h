#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Sence/Component.h"
#include "Runtime/Core/Container/Array.h"
#include "Runtime/OpenGL/Mesh.h"

namespace Star
{
class MeshComponent:public Component
{
public:
	virtual void Init() override;

	virtual void Tick() override;

	virtual void Exit() override;
public:
	void SetVisible(bool visbale);

	bool IsVisible() const;
public:
	// 
	Mesh m_mesh;

	// 是否可见
	bool m_isVisible;
};
}// namespace Star