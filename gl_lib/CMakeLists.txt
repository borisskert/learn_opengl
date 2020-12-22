include_directories(lib/glfw/include)
add_subdirectory(lib/glfw)

include_directories(lib/glad)
add_subdirectory(lib/glad)

file(GLOB_RECURSE SOURCES src/*.h src/*.cpp)

add_library(gl_lib STATIC ${SOURCES})
target_link_libraries(gl_lib PUBLIC glad PUBLIC glfw ${GLFW_LIBRARIES})
