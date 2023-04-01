#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader
{
private:
	uint32_t m_program;
	Shader();
	~Shader();

	static Shader *s_instance;
public:
	uint32_t program();
	void setMatrix(const char *name, const glm::mat4 &mat);
	void setVec4(const char *name, const glm::vec4 &v4);
public:
	static void init();
	static Shader *get();
	static void destroy();
};
