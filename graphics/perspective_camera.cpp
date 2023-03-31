#include "perspective_camera.h"
#include <glm/gtc/matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(
		float fov,
		float aspect,
		glm::vec3 upVec,
		float near,
		float far
		)
	: m_fov(fov),
	  m_aspect(aspect),
	  m_upVec(upVec),
	  m_near(near),
	  m_far(far)
{
}

PerspectiveCamera::~PerspectiveCamera()
{
}

const glm::mat4 &PerspectiveCamera::getVP()
{
	glm::mat4 view = glm::lookAt(
			m_position,
			m_lookAt,
			m_upVec
	);

	glm::mat4 proj = glm::perspective(
			m_fov,
			m_aspect,
			m_near,
			m_far
	);

	m_VP = view * proj;
	return m_VP;
}

void PerspectiveCamera::lookAt(const glm::vec3 pos)
{
	m_lookAt = pos;
}
