#pragma once
#include <glm/glm.hpp>

/*! the class from which all objects in a scene must inherit */

class Object
{
protected:
	
	glm::vec3
		m_position /*! the position of the object */, 
		m_origin /*! the origin of the object */,
		m_rotation, /*! the rotation of the object */
		m_scale; /*! the scale of the object */
public:
	Object();
	virtual ~Object() {}

	/*! \brief get the global transform of the object */
	glm::mat4 getTransform();
	/*! \brief get the position of the object*/
	glm::vec3 &position();
	/*! \brief get the origin of the object*/
	glm::vec3 &origin();
	/*! \brief get the scale of the object*/
	glm::vec3 &scale();
	/*! \brief get the rotation of the object*/
	glm::vec3 &rotation();

	/*! \brief set the position of the object */
	void setPosition(const glm::vec3 &newPosition);
	/*! \brief set the origin of the object */
	void setOrigin(const glm::vec3 &newOrigin);
	/*! \brief set the rotation of the object */
	void setRotation(const glm::vec3 &newRotation);
	/*! \brief set the scale of the object */
	void setScale(const glm::vec3 &newScale);
	
};
