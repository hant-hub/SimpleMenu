target_sources(renderlib
PUBLIC 
    Renderer.cpp
    Renderer.h
    transparency.cpp
    transparency.h
    Batched.h 
    Batched.cpp
PRIVATE
    
)

add_subdirectory(images)