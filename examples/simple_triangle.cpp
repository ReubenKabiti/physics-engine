#include "graphics_application.h"
#include "perspective_camera.h"
#include "cube.h"

#include <cmath>

/* class Triangle : public Mesh */
/* { */
/* public: */
/* 	Tri */
/* }; */

class SimpleScene : public Scene
{
private:
	std::shared_ptr<Cube> m_cube;
public:
	void onCreate()
	{
		glClearColor(0, 0, 0, 1);
		m_cube = std::make_shared<Cube>();
		m_cube->init();
		m_cube->position().z = -5;
		m_cube->setOrigin(glm::vec3(-0.5, -0.5, 0.5));
	}

	void onUpdate(float delta)
	{
		m_cube->rotation().x += M_PI / 4 * delta;
		m_cube->rotation().y += M_PI / 4 * delta;
	}

	void onRender()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		m_cube->render();
	}
	
	void onDestroy()
	{
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
