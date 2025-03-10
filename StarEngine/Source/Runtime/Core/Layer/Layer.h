#pragma once
#include<string>
#include"Common/Events/Event.h"
namespace Star 
{
class Layer
{
public:
	Layer(const std::string& name = "Layer")
		: m_name(name)
	{}

	virtual ~Layer() = default;

	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void Tick() {}
	virtual void OnEvent(Event& event) {}

	const std::string& GetName() const { return m_name; }
protected:
	std::string m_name;
};

}// namespace Star 