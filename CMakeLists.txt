cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project "lab8")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        src/main.cpp src/StringTask/tasks.cpp)

set(${project}_HEADERS
        src/StringTask/tasks.h)

# add_subdirectory(src/collections)
# add_subdirectory(src/app)
# add_subdirectory(src/product)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

# target_link_libraries(${project} collections)
# target_link_libraries(${project} app)
# target_link_libraries(${project} product)
