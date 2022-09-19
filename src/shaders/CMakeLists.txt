FILE(GLOB VERT "*.vert")
FILE(GLOB FRAG "*.frag")


foreach(Shader IN LISTS VERT)
    FILE(COPY "${Shader}" DESTINATION "${CMAKE_BINARY_DIR}/shaders")
endforeach()

foreach(Shader IN LISTS FRAG)
    FILE(COPY "${Shader}" DESTINATION "${CMAKE_BINARY_DIR}/shaders")
endforeach()
