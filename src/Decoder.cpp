#include <fstream>
#include <string>
#include <iostream>

#include "../include/Decoder.hpp"

std::unique_ptr<std::vector<std::vector<std::vector<int>>>> Decoder::extractPixelMap(std::ifstream &image_file, const std::string extension)
{
    std::unique_ptr<std::vector<std::vector<std::vector<int>>>> pixelmap = std::make_unique<std::vector<std::vector<std::vector<int>>>>();

    if (extension == "bmp")
    {
        // Extract pixel map offset
        image_file.seekg(10, std::ios_base::beg);
        uint32_t offset;
        image_file.read(reinterpret_cast<char *>(&offset), sizeof(offset));

        // Extract width and height
        image_file.seekg(18, std::ios_base::beg);
        uint32_t width, height;
        image_file.read(reinterpret_cast<char *>(&width), sizeof(width));
        image_file.read(reinterpret_cast<char *>(&height), sizeof(height));

        // Seek to pixel map
        image_file.seekg(offset, std::ios_base::beg);

        for (int i = 0; i < height; i++)
        {
            std::vector<std::vector<int>> line;
            for (int j = 0; j < width; j++)
            {
                std::vector<int> pixel_channels;
                for (int k = 0; k < 3; k++)
                {
                    uint8_t pixel_channel;
                    image_file.read(reinterpret_cast<char *>(&pixel_channel), sizeof(pixel_channel));
                    pixel_channels.insert(pixel_channels.begin(), pixel_channel);
                }
                line.push_back(pixel_channels);
            }
            pixelmap->insert(pixelmap->begin(), line);
        }
    }
    else
    {
        throw std::runtime_error("[Reading] Unsupported image type.");
    }
    return pixelmap;
}

void Decoder::checkFileType(const std::string extension)
{
    if (extension == "bmp")
    {
        std::cout << "Success." << std::endl;
    }
    else
    {
        throw std::runtime_error("Unsupported image type.");
    }
}