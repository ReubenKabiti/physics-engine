#include "graphics_application.h"
#include "perspective_camera.h"
#include <cmath>

class Triangle : public Mesh
{
public:
	Triangle()
	{
		float vertices[] = {
			0, 0.5, -1.0f,
			-0.5, -0.5, -1.0f,
			0.5, -0.5, -1.0f
		};

		uint32_t indices[] = {
			0, 1, 2
		};
		m_nIndices = 3;

		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);
		
		glGenBuffers(1, &m_vbo);
		glGenBuffers(1, &m_ebo);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
	}
};

class SimpleScene : public Scene
{
private:

	Triangle *m_triangle;
public:
	void onCreate()
	{
		glClearColor(0, 0, 0, 1);
		m_triangle = new Triangle;
	}

	void onRender()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		m_triangle->render();
	}
	
	void onDestroy()
	{
		delete m_triangle;
	}
};

int main()
{
	std::shared_ptr<PerspectiveCamera> camera = std::make_shared<PerspectiveCamera>(M_PI/3.0f, 800.0f/600.0f);
	camera->lookAt(glm::vec3(0, 0, -1));

	GraphicsApplication(
			std::make_shared<SimpleScene>(),
			camera,
			800, 600, "simple triangle"
	);

	return 0;
}
