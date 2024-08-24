cmake_minimum_required(VERSION 3.24)

add_library(compilers_flags INTERFACE)
target_compile_features(compilers_flags INTERFACE cxx_std_23)

add_library(yaga STATIC core.cxx)
target_include_directories(yaga PRIVATE ${PROJECT_SOURCE_DIR}/include
                                        ${PROJECT_BINARY_DIR}/include)
target_include_directories(yaga INTERFACE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(yaga PUBLIC compilers_flags)

option(SYSTEM_DEPENDENCY "Turn it ON to link with system packages" ON)

if(SYSTEM_DEPENDENCY)
find_package(SDL3)
    if(SDL3_FOUND)
        message("SDL3 lib was found")
        target_link_libraries(yaga PRIVATE SDL3::SDL3)
        target_include_directories(yaga PRIVATE SDl3::Header)
    else()
        message("Can't find SDL3 system package")
    endif()
endif()
