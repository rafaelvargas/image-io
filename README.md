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

## Running tests
Some tests are in the _test_ folder. To compile them, the following commands are suggested:

```bash
mkdir build
cd build
cmake ..
make
./testcase [arguments]
```

## Supported image file formats
* BMP (Bitmap)