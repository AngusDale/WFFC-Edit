#pragma once
#include "Command.h"
#include <SimpleMath.h>

class PositionCommand : public Command
{
public:
	PositionCommand(DirectX::SimpleMath::Vector3& elementPos)
		: m_oldPos(elementPos), m_elementPos(elementPos) {}

	void SetNewPos(DirectX::SimpleMath::Vector3 newPos)	{ m_newPos = newPos; }

	void undo() override { m_elementPos = m_oldPos; }
	void redo() override { m_elementPos = m_newPos; }

private:
	DirectX::SimpleMath::Vector3 m_oldPos;
	DirectX::SimpleMath::Vector3 m_newPos;
	DirectX::SimpleMath::Vector3& m_elementPos;
};
