#include "graphics_application.h"
#include "perspective_camera.h"
#include "cube.h"
#include "sphere.h"

#include <cmath>

class SimpleScene : public Scene
{
private:
	std::shared_ptr<Cube> m_cube;
	std::shared_ptr<Sphere> m_sphere;

public:
	void onCreate()
	{
		glClearColor(0, 0, 0, 1);
		m_cube = std::make_shared<Cube>();
		m_sphere = std::make_shared<Sphere>();

		m_cube->init();
		m_sphere->init();

		m_cube->position().z = -5;
		m_cube->setOrigin(glm::vec3(-0.5, -0.5, 0.5));
		m_cube->setColor({0, 1, 0, 1});

		m_sphere->position().z = -5;
		m_sphere->origin().z = 3;
		m_sphere->setColor({1, 0, 0, 1});

	}

	void onUpdate(float delta)
	{
		m_cube->rotation().x += M_PI / 4 * delta;
		/* m_cube->rotation().y += M_PI / 4 * delta; */
		m_sphere->rotation().y += M_PI / 4 * delta;
	}
	void onRender()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		m_cube->render();
		m_sphere->render();
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
			800, 600, "Very simple example"
	);

	return 0;
}
