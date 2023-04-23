#include "Camera.h"

Camera::Camera(Vector3 position, Vector3 lookAt) :
	m_rotRate(50),
	m_rotSensitivity(3),
	m_moveSpeed(10.f),

	m_position(position),
	m_orientation(Vector3::Zero),
	m_lookAt(lookAt),
	m_lookDirection(lookAt),
	m_right(Vector3::Zero),
	m_up(Vector3::UnitY)
{
}

void Camera::Update(const float dt)
{
	//TODO  any more complex than this, and the camera should be abstracted out to somewhere else
	//camera motion is on a plane, so kill the 7 component of the look direction
	Vector3 planarMotionVector = m_lookDirection;
	planarMotionVector.y = 0.0;
	
	auto ToRadians = [](float x) { return x * 3.1415 / 180; };

	// sphere equation
	m_lookDirection.x = cos(ToRadians(m_orientation.y)) * cos(ToRadians(m_orientation.x));
	m_lookDirection.y = sin(ToRadians(m_orientation.x));
	m_lookDirection.z = sin(ToRadians(m_orientation.y)) * cos(ToRadians(m_orientation.x));
	m_lookDirection.Normalize();

	//create right vector from look Direction
	m_lookDirection.Cross(Vector3::UnitY, m_right);	

	//update lookat point
	m_lookAt = m_position + m_lookDirection;

	//apply camera vectors
	m_view = Matrix::CreateLookAt(m_position, m_lookAt, Vector3::UnitY);

}

bool Camera::HandleInput(const InputCommands& input, const float dt)
{
	if (input.rotRight)
	{
		m_orientation.y += m_rotRate * dt;
	}
	if (input.rotLeft)
	{
		m_orientation.y -= m_rotRate * dt;
	}

	Vector3 moveDirection = Vector3::Zero;
	//process input and update stuff
	if (input.forward)
	{
		moveDirection += m_lookDirection;
	}
	if (input.back)
	{
		moveDirection -= m_lookDirection;
	}
	if (input.right)
	{
		moveDirection += m_right;
	}
	if (input.left)
	{
		moveDirection -= m_right;
	}
	moveDirection.Normalize();
	m_position += (moveDirection * m_moveSpeed * dt);

	return true;
}
