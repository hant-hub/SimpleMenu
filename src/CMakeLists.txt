cmake_minimum_required(VERSION 3.16.3)

project("RenderingEngine")

#library stuff
add_library(renderlib)
add_subdirectory(lib)
add_subdirectory(Engine)
add_subdirectory(shaders)
add_subdirectory(images)
target_include_directories(renderlib PUBLIC Engine)

#target_include_directories(renderlib ".")

#testing stuff
add_executable(test)
target_sources(test PUBLIC main.cpp)
target_link_libraries(test renderlib)