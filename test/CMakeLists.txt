cmake_minimum_required(VERSION 3.21)

add_executable(version version.cxx)
add_executable(init init.cxx)
add_executable(handle handle.cxx)
target_link_libraries(version PRIVATE yaga)
target_link_libraries(init PRIVATE yaga)
target_link_libraries(handle PRIVATE yaga)
