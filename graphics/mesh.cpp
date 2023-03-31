#include "mesh.h"
#include "shader.h"
#include <GL/glew.h>

void Mesh::render()
{
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	Shader::get()->setMatrix("model", getTransform());

	glDrawElements(GL_TRIANGLES, m_nIndices, GL_UNSIGNED_INT, nullptr);
}

