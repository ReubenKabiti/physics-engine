#pragma once
#include "camera.h"

class PerspectiveCamera : public Camera
{

private:
	float m_fov, m_aspect, m_near, m_far;
	glm::vec3 m_lookAt{0}, m_upVec;

public:
	PerspectiveCamera(
			float fov,
			float aspect,
			glm::vec3 upVec,
			float near = 0.1f,
			float far = 1000.0f
	);

	~PerspectiveCamera();

	virtual glm::mat4 getVP() override;

	void lookAt(const glm::vec3 pos);
};
