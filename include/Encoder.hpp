#pragma once

#include <fstream>
#include <string>

#include "Image.hpp"

class Encoder
{
public:
  void dumpPixelMap(Image &image, std::ofstream &image_file, const std::string extension);
};