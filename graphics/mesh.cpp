#include "mesh.h"
#include "shader.h"
#include <GL/glew.h>

void Mesh::init()
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);


	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), m_vertices.data(), GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * 4, m_indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr); // positions
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); // normals
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Mesh::render()
{
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	Shader::get()->setMatrix("model", getTransform());
	Shader::get()->setVec4("albedo", m_color);

	uint32_t nIndices = m_indices.size();
	glDrawElements(GL_TRIANGLES, nIndices, GL_UNSIGNED_INT, nullptr);
}


glm::vec4 &Mesh::color()
{
	return m_color;
}

void Mesh::setColor(const glm::vec4 &newColor)
{
	m_color = newColor;
}
