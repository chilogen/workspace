project(print)
add_subdirectory(src)
add_subdirectory(shared)
install(TARGETS a libprint RUNTIME DESTINATION bin LIBRARY DESTINATION lib)
