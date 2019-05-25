#include <iostream>
#include <vector>
#include <string>

#include "../include/Encoder.hpp"
#include "../include/Image.hpp"

void Encoder::dumpPixelMap(Image &image, std::ofstream &image_file, const std::string extension)
{
    if (extension == "bmp")
    {
        // File Header - 14 Bytes
        uint16_t signature = 19778;            /* Magic identifier */
        uint32_t file_size;                    /* The size of the BMP file in bytes */
        uint16_t reserved1 = 0, reserved2 = 0; /* Reserved; actual value depends on the application that creates the image */
        uint32_t offset = 54;                  /* The offset, i.e. starting address, of the byte where the bitmap image data (pixel array) can be found. */

        // Image Header - 40 Bytes
        uint32_t header_size = 40;                                    /* Header size in bytes      */
        int32_t width = image.getWidth(), height = image.getHeight(); /* Width and height of image */
        uint16_t planes = 1;                                          /* Number of colour planes   */
        uint16_t bits = 24;                                           /* Bits per pixel            */
        uint32_t compression = 0;                                     /* Compression type - BI_RGB */
        uint32_t image_size = 0;                                      /* Image size in bytes       */
        int32_t x_resolution = 0, y_resolution = 0;                   /* Pixels per meter          */
        uint32_t num_colors = 0;                                      /* Number of colours         */
        uint32_t important_colors = 0;                                /* Important colours         */

        file_size = 14 + 40 + (width * height * 3);

        image_file.write(reinterpret_cast<char *>(&signature), sizeof(signature));
        image_file.write(reinterpret_cast<char *>(&file_size), sizeof(file_size));
        image_file.write(reinterpret_cast<char *>(&reserved1), sizeof(reserved1));
        image_file.write(reinterpret_cast<char *>(&reserved2), sizeof(reserved2));
        image_file.write(reinterpret_cast<char *>(&offset), sizeof(offset));

        image_file.write(reinterpret_cast<char *>(&header_size), sizeof(header_size));
        image_file.write(reinterpret_cast<char *>(&width), sizeof(width));
        image_file.write(reinterpret_cast<char *>(&height), sizeof(height));
        image_file.write(reinterpret_cast<char *>(&planes), sizeof(planes));
        image_file.write(reinterpret_cast<char *>(&bits), sizeof(bits));
        image_file.write(reinterpret_cast<char *>(&compression), sizeof(compression));
        image_file.write(reinterpret_cast<char *>(&image_size), sizeof(image_size));
        image_file.write(reinterpret_cast<char *>(&x_resolution), sizeof(x_resolution));
        image_file.write(reinterpret_cast<char *>(&y_resolution), sizeof(y_resolution));
        image_file.write(reinterpret_cast<char *>(&num_colors), sizeof(num_colors));
        image_file.write(reinterpret_cast<char *>(&important_colors), sizeof(important_colors));

        for (int i = height - 1; i >= 0; i--)
        {
            for (int j = 0; j < width; j++)
            {
                for (int k = 2; k >= 0; k--)
                {
                    image_file.write(reinterpret_cast<char *>(&image[i][j][k]), sizeof(uint8_t));
                }
            }
        }
    } else if(extension == "ppm")
    {
        image_file << "P3" << std::endl;
        image_file << image.getWidth() << " " << image.getHeight() << std::endl;
        image_file << 255 << std::endl;
        
        for (int i = 0; i < image.getHeight(); i++)
        {
            for (int j = 0; j < image.getWidth(); j++)
            {
                image_file << image[i][j][0] << " " << image[i][j][1] << " " << image[i][j][2] << std::endl;
            }
        }
    }
    else
    {
        throw std::runtime_error("[Writing] Unsupported image type.");
    }
}