#pragma once

#include <string>
#include <vector>
#include <memory>

class Image
{
public:
  Image(const std::string filepath);
  void read(const std::string filepath);
  void write(const std::string filepath);
  int getWidth();
  int getHeight();
  std::vector<std::vector<int>> &operator[](const int row_index);

private:
  int height, width;
  std::unique_ptr<std::vector<std::vector<std::vector<int>>>> pixelmap;
};