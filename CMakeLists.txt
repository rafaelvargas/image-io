cmake_minimum_required (VERSION 2.6)
project (image-io)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(negative ${SOURCES} "test/negative.cpp")