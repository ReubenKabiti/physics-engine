cmake_minimum_required(VERSION 3.0)

project(physics_engine)

set(CMAKE_CXX_FLAGS "-Wall -ggdb")

add_subdirectory(physics)
add_subdirectory(graphics)
add_subdirectory(examples)

# ignore tests for now
# add_subdirectory(tests)
