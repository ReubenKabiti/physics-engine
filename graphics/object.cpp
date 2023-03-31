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

	matrix = glm::rotate(matrix, m_rotation.x, glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, m_rotation.y, glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, m_rotation.z, glm::vec3(0, 0, 1));

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

void Object::setPosition(const glm::vec3 &newPosition)
{
	m_position = newPosition;
}

void Object::setRotation(const glm::vec3 &newRotation)
{
	m_rotation = newRotation;
}

void Object::setScale(const glm::vec3 &newScale)
{
	m_scale = newScale;
}
