#include "graphics_application.h"

GraphicsApplication::GraphicsApplication(
			std::shared_ptr<Scene> mainScene,
			std::shared_ptr<Camera> mainCamera,
			uint32_t width,
			uint32_t height,
			const char *title
	)
{
	m_mainScene = mainScene;
	m_mainCamera = mainCamera;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(m_window);

	glewInit();
	glEnable(GL_DEPTH_TEST);

	Shader::init();
	m_mainScene->onCreate();
	mainLoop();
}

GraphicsApplication::~GraphicsApplication()
{
	m_mainScene->onDestroy();
	Shader::destroy();
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void GraphicsApplication::mainLoop()
{
	float delta = 0;
	while (!glfwWindowShouldClose(m_window))
	{
		float frameStartTime = glfwGetTime();
		glfwPollEvents();
		m_mainScene->onUpdate(delta);

		glm::mat4 VP = m_mainCamera->getVP();

		Shader::get()->setMatrix("VP", VP);
		glClear(GL_DEPTH_BUFFER_BIT);
		m_mainScene->onRender();
		glfwSwapBuffers(m_window);
		delta = glfwGetTime() - frameStartTime;
	}
}
