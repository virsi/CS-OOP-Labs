cmake_minimum_required(VERSION 3.20)

set(p "polynomial")
project(p)

set(${p}_SOURCES
  Polynomial.cpp
)

set(${p}_HEADERS
  Polynomial.hpp
)

add_library(${p} STATIC ${${p}_SOURCES} ${${p}_HEADERS})
