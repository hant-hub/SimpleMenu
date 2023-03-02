FILE(REAL_PATH "moveShader.py" SCRIPT2)

find_package(PythonInterp)
find_package(Python)

add_custom_target(moveshaders ALL
COMMAND python3 "${SCRIPT2}" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_BINARY_DIR}/shaders" "test.png"
)
