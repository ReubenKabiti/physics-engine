#pragma once
#include "camera.h"

/*! \brief PerspectiveCamera is a camera that uses perspective projection */

class PerspectiveCamera : public Camera
{

private:
	float m_fov;
	float m_aspect;
	float m_near;
	float m_far;

	glm::vec3 m_upVec;
	glm::vec3 m_lookAt{0};

public:
	/*!
	 * @param fov the field of view
	 * @param aspect the aspect ratio
	 * @param upVec the upward vector
	 * @param near the distance to the near plane
	 * @param far the distance to the far plane
	 */
	PerspectiveCamera(
			float fov,
			float aspect,
			glm::vec3 upVec = glm::vec3(0, 1, 0),
			float near = 0.1f,
			float far = 1000.0f
	);

	~PerspectiveCamera();

	/*! documented in Camera */
	virtual const glm::mat4 &getVP() override;

	/*! \brief set the look at direction of the camera 
	 * @param pos the position to look at
	 */
	void lookAt(const glm::vec3 pos);
};
