include("${PROJECT_SOURCE_DIR}/cmake/find_stb.cmake")

file(GLOB HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/gl_lib/*.h")
file(GLOB_RECURSE SOURCES *.cpp)

add_library(gl_lib ${SOURCES} ${HEADERS})
target_link_libraries(gl_lib PUBLIC glad PUBLIC glfw ${GLFW_LIBRARIES} PUBLIC glm)

target_include_directories(gl_lib PUBLIC ../include)
target_compile_features(gl_lib PUBLIC)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADERS}
)
