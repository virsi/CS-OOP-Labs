cmake_minimum_required(VERSION 3.20)
project(Lab4) # <- project name

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mystack/MyStack.cpp
)
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mystack/MyStack.h
)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_subdirectory(src/mystack)
target_link_libraries(${CMAKE_PROJECT_NAME} mystack)
