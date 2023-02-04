target_sources(renderlib
PUBLIC 
    Renderer.cpp
    Renderer.h
    unoptimized.cpp
    unoptimized.h
    Batched.h 
    Batched.cpp
PRIVATE
    
)

add_subdirectory(images)