#include "object.h"
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>

Object::Object()
	: m_position(0),
	  m_rotation(0),
	  m_scale(1)
{
}

glm::mat4 Object::getTransform()
{
	glm::mat4 matrix(1);
	matrix = glm::translate(matrix, m_position);

	// the rotation angles are in degrees
	// convert them to radians
	
	auto deg2rad = [](float deg)
	{
		return deg * M_PI / 180.0f;
	};
	
	float xRot = deg2rad(m_rotation.x);
	float yRot = deg2rad(m_rotation.y);
	float zRot = deg2rad(m_rotation.z);

	matrix = glm::rotate(matrix, xRot, glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, yRot, glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, zRot, glm::vec3(0, 0, 1));

	matrix = glm::scale(matrix, m_scale);
	return matrix;
}

glm::vec3 &Object::position()
{
	return m_position;
}

glm::vec3 &Object::scale()
{
	return m_scale;
}

glm::vec3 &Object::rotation()
{
	return m_rotation;
}
