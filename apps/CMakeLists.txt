configure_file("${PROJECT_SOURCE_DIR}/assets/textures/container.jpg" "assets/textures/container.jpg" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/textures/awesomeface.png" "assets/textures/awesomeface.png" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/textures/wall.jpg" "assets/textures/wall.jpg" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/textures/container2.png" "assets/textures/container2.png" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/textures/container2_specular.png" "assets/textures/container2_specular.png" COPYONLY)

configure_file("${PROJECT_SOURCE_DIR}/assets/shader/vertex.shader" "assets/shader/vertex.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/lightFragment.shader" "assets/shader/lightFragment.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/lightVertex.shader" "assets/shader/lightVertex.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/fragment.diffuse-and-specular-textured.shader" "assets/shader/fragment.diffuse-and-specular-textured.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/fragment.double-textured.shader" "assets/shader/fragment.double-textured.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/fragment.main.shader" "assets/shader/fragment.main.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/fragment.mono-texture.shader" "assets/shader/fragment.mono-texture.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/fragment.no-light.shader" "assets/shader/fragment.no-light.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/fragment.simple-color.shader" "assets/shader/fragment.simple-color.shader" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/assets/shader/fragment.simple-light.shader" "assets/shader/fragment.simple-light.shader" COPYONLY)


file(GLOB_RECURSE SOURCES *.h *.cpp)
add_executable(game_of_life_app ${SOURCES})
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
