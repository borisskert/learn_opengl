cmake_minimum_required(VERSION 3.16)
project(myfirstopengl)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE "SOURCES" "main.cpp" "src/*.cpp")

include_directories(include/glfw/include)
add_subdirectory(include/glfw)

include_directories(include/glad)
add_subdirectory(include/glad)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE glad PUBLIC glfw ${GLFW_LIBRARIES})
