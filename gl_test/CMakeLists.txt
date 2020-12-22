file(GLOB_RECURSE TEST_SOURCES src/*.cpp)

add_subdirectory(lib/googletest)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCES ${TEST_SOURCES})

add_executable(gl_test ${TEST_SOURCES})

add_test(NAME gl_test COMMAND gl_test)

target_link_libraries(gl_test PUBLIC gl_lib PUBLIC gtest gmock)
