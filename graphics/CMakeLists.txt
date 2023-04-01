add_library(
	graphics
	object.cpp
	perspective_camera.cpp
	mesh.cpp
	shader.cpp
	graphics_application.cpp
	cube.cpp
)

target_include_directories(
	graphics
	PUBLIC
	"../include/graphics"
)

target_link_libraries(
	graphics
	PUBLIC
	-lGL
	-lGLEW
	-lglfw3
	-lX11
)
