project(life)
cmake_minimum_required(VERSION 3.0)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


include_directories(include ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})
add_subdirectory(src)

add_executable(main src/main.cpp)
target_link_libraries(main draw config ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})