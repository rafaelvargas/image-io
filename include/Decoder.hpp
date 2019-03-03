#pragma once

#include <vector>
#include <fstream>
#include <string>

class Decoder
{
public:
  std::vector<std::vector<std::vector<int>>> extractPixelMap(std::ifstream &image_file, const std::string extension);

private:
  void checkFileType(const std::string extension);
};