cmake_minimum_required(VERSION 3.21)

add_library(compilers_flags INTERFACE)
target_compile_features(compilers_flags INTERFACE cxx_std_23)

add_library(yaga STATIC core.cxx)
target_include_directories(yaga PRIVATE ${PROJECT_SOURCE_DIR}/include
                                        ${PROJECT_BINARY_DIR}/include)
target_include_directories(yaga INTERFACE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(yaga PUBLIC compilers_flags)
