cmake_minimum_required(VERSION 3.16)
project(learn_opengl)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(extern/glfw)
add_subdirectory(extern/glad)
add_subdirectory(extern/glm)

add_subdirectory(src)
add_subdirectory(apps)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) OR BUILD_TESTING)
    add_subdirectory(extern/googletest)
    add_subdirectory(tests)
endif()
