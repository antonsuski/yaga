cmake_minimum_required(VERSION 3.21)

add_executable(version version.cxx)
target_link_libraries(version PRIVATE yaga)
# target_include_directories(version PRIVATE ${PROJECT_SOURCE_DIR}/include)
