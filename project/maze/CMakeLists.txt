cmake_minimum_required(VERSION 2.8)
PROJECT(maze)
include_directories(include ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
add_executable(maze src/main.cpp)
target_link_libraries(maze ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
