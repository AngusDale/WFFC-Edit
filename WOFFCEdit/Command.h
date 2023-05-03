#pragma once

class Command
{
	public:
	virtual ~Command() {};
	virtual void undo() = 0;
};