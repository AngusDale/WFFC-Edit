#pragma once
#include <stack>
#include "Command.h"

class CommandController
{
public:
	void PushToHistory(Command* command)
	{
		if (command)
			m_commandStack.push(command);
	}

	void Pop()
	{
		if (!m_commandStack.empty())
		{
			m_commandStack.top()->undo();
			m_commandStack.pop();
		}
	}

	void Clear()
	{
		while (!m_commandStack.empty())
		{
			m_commandStack.pop();
		}
	}

private:
	std::stack<Command*> m_commandStack;

};