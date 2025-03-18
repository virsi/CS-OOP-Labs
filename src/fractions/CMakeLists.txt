cmake_minimum_required(VERSION 3.20)

set(p "fractions")
project(p)

set(${p}_SOURCES
  Fractions.cpp
)

set(${p}_HEADERS
Fractions.h
)

add_library(${p} STATIC ${${p}_SOURCES} ${${p}_HEADERS})


