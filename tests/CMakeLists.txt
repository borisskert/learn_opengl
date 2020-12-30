set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES *.cpp)
add_executable(test_gl_lib ${SOURCES})

add_test(NAME test_gl_lib_test COMMAND test_gl_lib)

target_link_libraries(test_gl_lib PRIVATE gl_lib PRIVATE gtest gmock)

