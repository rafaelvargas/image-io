#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../include/Image.hpp"
#include "../include/Decoder.hpp"
#include "../include/Encoder.hpp"

Image::Image(const std::string filepath)
{
    this->read(filepath);
}

Image::Image(const int height, const int width)
{
    std::vector<std::vector<std::vector<int>>> pixelmap(std::vector<std::vector<std::vector<int>>>(height, std::vector<std::vector<int>>(width, std::vector<int>(3, 0))));
    this->pixelmap = std::make_unique<std::vector<std::vector<std::vector<int>>>>(pixelmap);
    this->height = height;
    this->width = width; 
}

void Image::read(const std::string filepath)
{
    std::ifstream input_file(filepath, std::ios::binary);
    if (input_file.is_open())
    {
        Decoder decoder;
        std::string file_extension = filepath.substr(filepath.find_last_of(".") + 1);
        this->pixelmap = decoder.extractPixelMap(input_file, file_extension);
        input_file.close();
        this->height = this->pixelmap->size();
        this->width = this->pixelmap->at(0).size();
    }
    else
    {
        throw std::runtime_error("Could not open image file in: " + filepath);
    }
}

void Image::write(const std::string filepath)
{
    std::ofstream output_file(filepath, std::ios::binary);
    if (output_file.is_open())
    {
        Encoder encoder;
        std::string file_extension = filepath.substr(filepath.find_last_of(".") + 1);
        encoder.dumpPixelMap(*this, output_file, file_extension);
        output_file.close();
    }
    else
    {
        throw std::runtime_error("Could not open output image file in: " + filepath);
    }
}

int Image::getWidth()
{
    return this->width;
}

int Image::getHeight()
{
    return this->height;
}

std::vector<std::vector<int>> &Image::operator[](const int row_index)
{
    return this->pixelmap->at(row_index);
}