#pragma once

#include "object.h"

/*! \brief camera is an abstract class that all cameras in the scene must inherit from */

class Camera : public Object
{
protected:
	glm::mat4 m_VP /*! the product matrix of the view and projection matrices*/;

public:
	virtual ~Camera() {}

	/*! get the product of the view and projection matrices */
	virtual const glm::mat4 &getVP() = 0;
};
