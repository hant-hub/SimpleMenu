FILE(REAL_PATH "packer.py" SCRIPT)

find_package(PythonInterp)
find_package(Python)

add_custom_target(do_always ALL
COMMAND python3 "${SCRIPT}" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_BINARY_DIR}/images" "test.png"
)