#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "camera.h"
#include "scene.h"
#include "shader.h"
#include "mesh.h"


class GraphicsApplication
{
private:

	std::shared_ptr<Scene> m_mainScene;
	std::shared_ptr<Camera> m_mainCamera;
	GLFWwindow *m_window;
public:
	GraphicsApplication(
			std::shared_ptr<Scene> mainScene,
			std::shared_ptr<Camera> mainCamera,
			uint32_t width,
			uint32_t height,
			const char *title = "Untitled Window"
	);

	~GraphicsApplication();

	void mainLoop();
};
