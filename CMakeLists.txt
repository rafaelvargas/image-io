cmake_minimum_required (VERSION 3.9)
project (image-io)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-O4")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

set(SOURCES ${SOURCE_DIR}/Image.cpp
            ${SOURCE_DIR}/Decoder.cpp
            ${SOURCE_DIR}/Encoder.cpp)

add_library(image-io ${SOURCES})

target_include_directories(image-io
    PUBLIC ${INCLUDE_DIR}
)