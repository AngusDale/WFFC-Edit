#pragma once
#include "pch.h" 
#include "InputCommands.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

class Camera
{
public:
	Camera();
	Camera(Vector3 position, Vector3 lookAt);

	bool HandleInput(const InputCommands& input, const float dt);
	void Update(const float dt);
	
private:
	const float		m_rotRate;
	const float		m_rotSensitivity;
	const float		m_moveSpeed;

	Vector3			m_position;
	Vector3			m_orientation;
	Vector3			m_lookAt;
	Vector3			m_lookDirection;
	Vector3			m_right;
	Vector3			m_up;

	Matrix			m_view;
	Matrix			m_projection;

public:
	Vector3 GetPosition()	const {		return m_position;		}
	Vector3 GetLookAt()		const {		return m_lookAt;		}
	Matrix	GetView()		const {		return m_view;			}
	Matrix	GetProjection()	const {		return m_projection;	}

	void SetProjection(const Matrix& proj) { m_projection = proj; };
};

