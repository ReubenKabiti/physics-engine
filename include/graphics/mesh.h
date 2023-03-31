#pragma once
#include "object.h"
#include <cstdint>

class Mesh : public Object
{
protected:
	uint32_t m_nIndices;
	uint32_t m_vao, m_vbo, m_ebo;

public:
	virtual ~Mesh(){}

	void render();
};
