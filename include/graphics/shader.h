#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

/*! Shader class */

class Shader
{
private:
	uint32_t m_program;
	Shader();
	~Shader();

	static Shader *s_instance;
public:
	/*! get the id for the shader program */
	uint32_t program();
	/*! set the named matrix in the shader
	 *  @param name the name of the uniform
	 *  @param mat the matrix that the uniform matrix will be set to
	 */
	void setMatrix(const char *name, const glm::mat4 &mat);
	/*! set the named 4 vector in the shader
	 * @param name the name of the 4 vector
	 * @param v4 the vector that the uniform 4 vector will be set to
	 */
	void setVec4(const char *name, const glm::vec4 &v4);

public:
	/*! initialize the shader */
	static void init();
	/*! get the singleton instance of the shader */
	static Shader *get();
	/*! release the resources acquired by the shader, and delete the singleton instance*/
	static void destroy();
};
