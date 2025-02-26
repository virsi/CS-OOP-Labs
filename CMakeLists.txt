cmake_minimum_required(VERSION 3.20)
project(Lab2) # <- project name


# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dbplanets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dbcomputers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interaction/interaction.cpp
)
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dbplanets.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dbcomputers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/interaction/interaction.hpp
)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

#target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)
add_custom_target(
    clang-format
    COMMAND clang-format
    --dry-run
    -Werror
    ${SOURCES}
    ${HEADERS}
)

add_subdirectory(src/planet)
add_subdirectory(src/computer)

target_link_libraries(${CMAKE_PROJECT_NAME} planet computer)
