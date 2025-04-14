cmake_minimum_required(VERSION 3.20)

set(p "collections")
project(p)

set(${p}_SOURCES
  vector.cpp
)

set(${p}_HEADERS
  vector.hpp
)

add_library(${p} STATIC ${${p}_SOURCES} ${${p}_HEADERS})
set_target_properties(${p} PROPERTIES LINKER_LANGUAGE CXX)
