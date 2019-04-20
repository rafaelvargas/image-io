# image-io

A simple library for reading and writing images.

## Usage
* All the source files in _src_ folder need to be compiled with your project.
* The header _Image.hpp_ should be included in your source code.

### Image Reading
A image is created from an input file.
```cpp
Image image("input_filename.extension");
```
### Image Creation
A image with all values set to zero is created.
```cpp
Image image(height, width);
```

### Image Writing
A image is stored as a file in a specific format. The extension needs to be specified.
```cpp
image.write("output_filename");
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
* PPM (Portable Pixmap)