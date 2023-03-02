FILE(REAL_PATH "packer.py" SCRIPT1)

find_package(PythonInterp)
find_package(Python)

add_custom_target(packimages ALL
COMMAND python3 "${SCRIPT1}" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_BINARY_DIR}/images" "test.png"
)
