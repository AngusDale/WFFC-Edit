#pragma once
#include <algorithm>
#include <vector>
#include "Command.h"

template <class T> 
class Paste : public Command
{
public:
	Paste(T element,  int index, std::vector<T>& container)
	: m_element(element), m_index(index), m_container(container){}

	void undo() override
	{
		m_container.erase(m_container.begin() + m_index);
	}

	void redo() override
	{
		m_container.push_back(m_element);
		m_index = m_container.size() - 1;
	}

private:
	std::vector<T>& m_container;
	T m_element;
	int m_index;
};
