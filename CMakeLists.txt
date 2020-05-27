cmake_minimum_required(VERSION 3.15)
project(cg C)
set(CMAKE_C_STANDARD 99)

include_directories(GL/)

add_executable(cg main.c)

target_link_libraries(cg -lOpenGL32 -lfreeGLUT -lglu32 -lopengl32)

