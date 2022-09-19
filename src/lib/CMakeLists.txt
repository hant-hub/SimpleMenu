find_package(Freetype)
target_include_directories(renderlib PUBLIC "${FREETYPE_INCLUDE_DIRS}")
target_link_libraries(renderlib ${FREETYPE_LIBRARY})

add_library(glad)
add_subdirectory(glad)
target_link_libraries(renderlib glad)

add_subdirectory(glfw)
include_directories(glfw/include/GLFW)
target_link_libraries(renderlib glfw ${GLFW_LIBRARIES})

add_subdirectory(glm)
include_directories(glm/glm)
target_link_libraries(renderlib glm)

add_subdirectory(stbimage)
target_include_directories(renderlib PUBLIC STBIMAGE)