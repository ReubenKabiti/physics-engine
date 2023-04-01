add_executable(physics_engine simple_triangle.cpp)
target_link_libraries(physics_engine PUBLIC graphics)
target_include_directories(physics_engine PUBLIC "../include/graphics/")
