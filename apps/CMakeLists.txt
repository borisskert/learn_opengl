configure_file("${PROJECT_SOURCE_DIR}/assets/textures/container.jpg" "assets/textures/container.jpg" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/textures/awesomeface.png" "assets/textures/awesomeface.png" COPYONLY)

configure_file("${PROJECT_SOURCE_DIR}/assets/shader/vertex.shader" "assets/shader/vertex.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/colored.fragment.shader" "assets/shader/colored.fragment.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/textured.fragment.shader" "assets/shader/textured.fragment.shader" COPYONLY)


add_executable(game_of_life_app main.cpp)
target_link_libraries(game_of_life_app PRIVATE gl_lib)


file(GLOB_RECURSE SHADER_FILES ${PROJECT_SOURCE_DIR}/assets/shader/*.*)
install(
        FILES ${SHADER_FILES}
        DESTINATION "${CMAKE_INSTALL_BINDIR}/assets/shader"
)

file(GLOB_RECURSE TEXTURE_FILES ${PROJECT_SOURCE_DIR}/assets/textures/*.*)
install(
        FILES ${TEXTURE_FILES}
        DESTINATION "${CMAKE_INSTALL_BINDIR}/assets/textures"
)

install(
        TARGETS game_of_life_app
        RUNTIME DESTINATION bin
)
