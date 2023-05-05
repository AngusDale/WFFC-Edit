#pragma once
#include <stack>
#include "Command.h"

class CommandController
{
public:
	CommandController(int memory) : m_memory(memory), m_cachedCommand(nullptr)
	{
		m_undoStack.reserve(memory);
		m_redoStack.reserve(memory);
	}

	void PushNewCommand(Command* command)
	{
		if (command)
			m_undoStack.push_back(command);

		if(m_undoStack.size() > m_memory)
		{
			delete m_undoStack.front();
			m_undoStack.erase(m_undoStack.begin());
		}

		while(!m_redoStack.empty())
		{
			delete m_redoStack.back();
			m_redoStack.pop_back();
		}
	}

	void Undo()
	{
		if (!m_undoStack.empty())
		{
			m_undoStack.back()->undo();
			m_redoStack.push_back(m_undoStack.back());
			m_undoStack.pop_back();
		}
	}

	void Redo()
	{
		if (!m_redoStack.empty())
		{
			m_redoStack.back()->redo();
			m_undoStack.push_back(m_redoStack.back());
			m_redoStack.pop_back();
		}
	}

	Command* Top() { return m_undoStack.back(); }
	
	Command* m_cachedCommand;

private:

	std::vector<Command*> m_undoStack;
	std::vector<Command*> m_redoStack;


	const int m_memory;
};