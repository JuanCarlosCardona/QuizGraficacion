cmake_minimum_required(VERSION 3.23)
project(quiz_graficacion)

set(CMAKE_CXX_STANDARD 14)
set(OpenGlLinkers -lglut -lGLU -lGL -lGLEW)

add_executable(quiz_graficacion main.cpp)
target_link_libraries(quiz_graficacion ${OpenGlLinkers})