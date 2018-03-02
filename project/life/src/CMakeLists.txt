add_library(draw SHARED draw.cpp)
add_library(config SHARED config.cpp)
add_library(evolution SHARED evolution.cpp)

target_link_libraries(draw evolution ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})