#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <memory>

class Decoder
{
public:
  std::unique_ptr<std::vector<std::vector<std::vector<int>>>> extractPixelMap(std::ifstream &image_file, const std::string extension);

private:
  void checkFileType(const std::string extension);
};