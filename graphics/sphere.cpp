#include "sphere.h"
#include <cmath>
#include <iostream>

Sphere::Sphere(uint32_t nDivs)
{
	// the math is kinda wrong I'll fix it later
	float theta = -2.0f * M_PI;

	float dtheta = M_PI / nDivs;
	float dphi = 2.0f * M_PI / nDivs;

	auto gen = [&](float phi)
	{
		glm::vec3 point;
		point.x = cos(theta) * cos(phi);
		point.y = sin(theta);
		point.z = -cos(theta) * sin(phi);
		return point;
	};

	uint32_t index = 0;
	while (theta <= 4.0f * M_PI)
	{
		float phi = 0.0f;
		while(phi <= 2.0f * M_PI)
		{
			glm::vec3 point1 = gen(phi);
			theta += dtheta;
			glm::vec3 point2 = gen(phi);
			phi += dphi;
			glm::vec3 point3 = gen(phi);
			theta -= dtheta;
			glm::vec3 point4 = gen(phi);

			// positions
			m_vertices.push_back(point1.x);
			m_vertices.push_back(point1.y);
			m_vertices.push_back(point1.z);
			// normals
			m_vertices.push_back(point1.x);
			m_vertices.push_back(point1.y);
			m_vertices.push_back(point1.z);


			// positions
			m_vertices.push_back(point2.x);
			m_vertices.push_back(point2.y);
			m_vertices.push_back(point2.z);
			// normals
			m_vertices.push_back(point2.x);
			m_vertices.push_back(point2.y);
			m_vertices.push_back(point2.z);

			// positions
			m_vertices.push_back(point3.x);
			m_vertices.push_back(point3.y);
			m_vertices.push_back(point3.z);
			// normals
			m_vertices.push_back(point3.x);
			m_vertices.push_back(point3.y);
			m_vertices.push_back(point3.z);

			// positions
			m_vertices.push_back(point4.x);
			m_vertices.push_back(point4.y);
			m_vertices.push_back(point4.z);
			// normals
			m_vertices.push_back(point4.x);
			m_vertices.push_back(point4.y);
			m_vertices.push_back(point4.z);

			m_indices.push_back(1 + index);
			m_indices.push_back(0 + index);
			m_indices.push_back(2 + index);
			m_indices.push_back(2 + index);
			m_indices.push_back(0 + index);
			m_indices.push_back(3 + index);
			index ++;
		}
		theta += dtheta;
	}
}
