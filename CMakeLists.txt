cmake_minimum_required (VERSION 2.6)
project (image-io)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "-std=c++17")
endif()

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(negative ${SOURCES} "test/negative.cpp")
add_executable(image-creation ${SOURCES} "test/image-creation.cpp")
add_executable(contrast ${SOURCES} "test/contrast.cpp")