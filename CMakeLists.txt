cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project "lab5")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        src/main.cpp)

# set(${project}_SOURCES
#         tests/test_myvector.cpp)

# set(${project}_SOURCES
#         tests/test_myset.cpp)

add_subdirectory(containers)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} containers)
