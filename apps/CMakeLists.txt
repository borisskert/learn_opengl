configure_file("${PROJECT_SOURCE_DIR}/assets/textures/container.jpg" "assets/textures/container.jpg" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/textures/awesomeface.png" "assets/textures/awesomeface.png" COPYONLY)

configure_file("${PROJECT_SOURCE_DIR}/shader/vertex.shader" "shader/vertex.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/shader/fragment.shader" "shader/fragment.shader" COPYONLY)

add_executable(game_of_life_app main.cpp)
target_link_libraries(game_of_life_app PRIVATE gl_lib)
