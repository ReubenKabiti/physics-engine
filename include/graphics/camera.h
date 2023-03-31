#pragma once

#include "object.h"

class Camera : public Object
{
public:
	virtual ~Camera() {}

	// get the view projection matrix
	virtual glm::mat4 getVP() = 0;
};
