#pragma once
#include <algorithm>
#include <vector>
#include "Command.h"

template <class T> 
class Paste : public Command
{
public:
	Paste(int index, std::vector<T>& container)
	: m_index(index), m_container(container){}

	void undo() override
	{
		m_container.erase(m_container.begin() + m_index);
	}

private:
	std::vector<T>& m_container;
	const int m_index;
};
