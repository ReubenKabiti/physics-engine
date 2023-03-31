add_executable(
	physics_engine
	graphics.cpp
)

target_link_libraries(
	physics_engine
	PUBLIC
	-lgtest
	graphics
)
