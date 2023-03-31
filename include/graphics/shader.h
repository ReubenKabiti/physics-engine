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
	void setMatrix(const char *name, glm::mat4 mat);

public:
	static void init();
	static Shader *get();
	static void destroy();
};
