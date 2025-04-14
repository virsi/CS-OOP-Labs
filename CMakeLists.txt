cmake_minimum_required(VERSION 3.20)
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(Polynomial)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_subdirectory(src/collections)
add_subdirectory(src/app)
add_subdirectory(src/polynomial)
target_link_libraries(${CMAKE_PROJECT_NAME} collections app polynomial)
