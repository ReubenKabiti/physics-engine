#include "object.h"
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>

Object::Object()
	: m_position(0),
	  m_origin(0),
	  m_rotation(0),
	  m_scale(1)
{
}

glm::mat4 Object::getTransform()
{
	glm::mat4 translation(1);
	glm::mat4 rotation(1);
	glm::mat4 scaling(1);

	translation = glm::translate(translation, m_origin);

	// the rotation
	rotation = glm::rotate(rotation, m_rotation.x, glm::vec3(1, 0, 0));
	rotation = glm::rotate(rotation, m_rotation.y, glm::vec3(0, 1, 0));
	rotation = glm::rotate(rotation, m_rotation.z, glm::vec3(0, 0, 1));

	glm::mat4 tr = rotation * translation;
	translation = glm::translate(glm::mat4(1), m_position);

	tr = translation * tr;
	scaling = glm::scale(scaling, m_scale);

	return scaling * tr;
}

glm::vec3 &Object::position()
{
	return m_position;
}

glm::vec3 &Object::origin()
{
	return m_origin;
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

void Object::setOrigin(const glm::vec3 &newOrigin)
{
	m_origin = newOrigin;
}

void Object::setRotation(const glm::vec3 &newRotation)
{
	m_rotation = newRotation;
}

void Object::setScale(const glm::vec3 &newScale)
{
	m_scale = newScale;
}

