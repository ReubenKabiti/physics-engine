#include "shader.h"
#include <glm/gtc/type_ptr.hpp>

Shader *Shader::s_instance = nullptr;

Shader::Shader()
{
	// vertex shader source
	const char *vss = "#version 330 core\n"
					  "layout (location = 0) in vec3 aPos;"
					  "layout (location = 1) in vec3 aNormal;"
					  "uniform mat4 VP;"
					  "uniform mat4 model;"
					  "out vec3 normal;"
					  "void main()"
					  "{"
					  " gl_Position = VP * model * vec4(aPos, 1);"
					  " normal = vec3(model * vec4(aNormal, 0));"
					  "}";

	const char *fss = "#version 330 core\n"
					  "in vec3 normal;"
					  "out vec4 color;"
					  "vec3 lightDir = vec3(-1, -1, 0);"
					  "uniform vec4 albedo = vec4(1, 1, 1, 1);"
					  "uniform float diffuse = 0.4;"
					  ""
					  "float getDiffuseFactor()"
					  "{"
					  " float fact = dot(normalize(normal), -normalize(lightDir));"
					  " return fact; "
					  "}"
					  "void main()"
					  "{"
					  " float fact = max(diffuse, getDiffuseFactor());"
					  "	color = albedo * fact;"
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
void Shader::setMatrix(const char *name, const glm::mat4 &mat)
{
	uint32_t loc = glGetUniformLocation(m_program, name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setVec4(const char *name, const glm::vec4 &v4)
{
	uint32_t loc = glGetUniformLocation(m_program, name);
	glUniform4f(loc, v4.r, v4.g, v4.b, v4.a);
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
