#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "camera.h"
#include "scene.h"

/*! \brief the main graphics application 
 * sets everything up and calls the main loop
*/

class GraphicsApplication
{
private:

	std::shared_ptr<Scene> m_mainScene;
	std::shared_ptr<Camera> m_mainCamera;
	GLFWwindow *m_window ;

public:
	/*!
	 * @param mainScene the main scene
	 * @param mainCamera the main camera
	 * @param width the viewport width
	 * @param height the viewport height
	 * @param title the window title
	 */
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
