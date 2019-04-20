# image-io

A simple library for reading and writing images.

## Usage
* All the source files in _src_ folder need to be compiled with your project.
* The header _Image.hpp_ should be included in your source code.

### With CMake
Considering image-io folder is in the root directory:
```cmake
add_subdirectory(image-io)
target_link_libraries(your_build_target image-io)
```

## Supported image file formats
* BMP (Bitmap)