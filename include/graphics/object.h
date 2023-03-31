#pragma once
#include <glm/glm.hpp>

class Object
{
protected:
	glm::vec3 m_position, m_scale, m_rotation;
public:
	Object();
	virtual ~Object() {}

	glm::mat4 getTransform();
	glm::vec3 &position();
	glm::vec3 &scale();
	glm::vec3 &rotation();
};
