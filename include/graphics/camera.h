#pragma once

#include "object.h"

class Camera : public Object
{
protected:
	glm::mat4 m_VP;
public:
	virtual ~Camera() {}

	// get the view projection matrix
	virtual const glm::mat4 &getVP() = 0;
};
