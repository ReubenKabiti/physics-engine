#pragma once
#include "object.h"
#include <cstdint>
#include <vector>

/*! \brief an abstract class for storing and rendering 3D objects */

class Mesh : public Object
{
protected:
	uint32_t m_vao /*! the vertex array object */;
	uint32_t m_vbo /*! the vertex buffer object */;
	uint32_t m_ebo /*! the element buffer object */;

	std::vector<float> m_vertices /*! the vertices */;
	std::vector<uint32_t> m_indices /*! the indices */;

	glm::vec4 m_color{1} /* the color of the object */;

public:
	virtual ~Mesh() {}
	/*! sets and up sends mesh data to the gpu */
	void init();
	/*! renders the mesh */
	void render();
	/*! get the color of the mesh */
	glm::vec4 &color();
	/*! set the color of the mesh */
	void setColor(const glm::vec4 &newColor);
};
