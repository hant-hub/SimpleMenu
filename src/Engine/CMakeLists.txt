target_sources(renderlib
PRIVATE
    window.cpp
    window.h
    shader.cpp 
    shader.h
    Precomp.cpp 
    inputs.h
    inputs.cpp
PUBLIC
    Precomp.h
)

add_subdirectory(Renderer)

target_precompile_headers(renderlib PUBLIC Precomp.h)