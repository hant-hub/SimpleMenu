target_sources(glad
PRIVATE
    src/glad.c
PUBLIC
    "include/glad/glad.h"
)

target_include_directories(glad PUBLIC include/)