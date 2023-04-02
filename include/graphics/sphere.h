#pragma once
#include "mesh.h"

class Sphere : public Mesh
{
public:
	/*!
	 * @param nDivs the number of patches that will form the sphere
	 */

	Sphere(uint32_t nDivs = 20);
};
