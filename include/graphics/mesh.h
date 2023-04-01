#pragma once
#include "object.h"
#include <cstdint>
#include <vector>

class Mesh : public Object
{
protected:
	uint32_t m_vao, m_vbo, m_ebo;
	std::vector<float> m_vertices;
	std::vector<uint32_t> m_indices;

	glm::vec4 m_color{1};

public:
	virtual ~Mesh() {}
	void init();
	void render();
	
	glm::vec4 &color();
	void setColor(const glm::vec4 &newColor);
};
