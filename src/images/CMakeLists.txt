FILE(GLOB IMGS "*.png")

foreach(IMG IN LISTS IMGS)
    FILE(COPY "${IMG}" DESTINATION "${CMAKE_BINARY_DIR}/images")
endforeach()