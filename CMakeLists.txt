cmake_minimum_required(VERSION 3.16)
project(myfirstopengl)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(gl_lib)
add_subdirectory(gl_test)

file(GLOB_RECURSE "SOURCES" "main.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC gl_lib)
