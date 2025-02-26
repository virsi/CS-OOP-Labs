cmake_minimum_required(VERSION 3.23)

set(project "lab1_2")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_HEADERS
        mymath.h)

set(${project}_SOURCES
        main.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} ${CMAKE_SOURCE_DIR}/libmymath.a)
