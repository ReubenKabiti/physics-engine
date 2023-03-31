#include "shader.h"
#include <glm/gtc/type_ptr.hpp>

Shader *Shader::s_instance = nullptr;

Shader::Shader()
{
	// vertex shader source
	const char *vss = "#version 330 core\n"
					  "layout (location = 0) in vec3 aPos;"
					  "uniform mat4 VP;"
					  "uniform mat4 model;"
					  "void main()"
					  "{"
					  " gl_Position = VP * model * vec4(aPos, 1);"
					  "}";
	const char *fss = "#version 330 core\n"
					  "out vec4 color;"
					  "void main()"
					  "{"
					  "	color = vec4(1, 1, 1, 1);"
					  "}";
	uint32_t vs = glCreateShader(GL_VERTEX_SHADER);
	uint32_t fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vs, 1, &vss, nullptr);
	glShaderSource(fs, 1, &fss, nullptr);

	glCompileShader(vs);
	glCompileShader(fs);

	m_program = glCreateProgram();
	glAttachShader(m_program, vs);
	glAttachShader(m_program, fs);
	glLinkProgram(m_program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	glUseProgram(m_program);
}

Shader::~Shader()
{
	glDeleteProgram(m_program);
}

uint32_t Shader::program()
{
	return m_program;
}
void Shader::setMatrix(const char *name, glm::mat4 mat)
{
	uint32_t loc = glGetUniformLocation(m_program, name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::init()
{
	if (s_instance == nullptr)
		s_instance = new Shader;
}

Shader *Shader::get()
{
	return s_instance;
}

void Shader::destroy()
{
	delete s_instance;
}