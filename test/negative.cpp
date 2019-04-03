#include <string>
#include <iostream>
#include "../include/Image.hpp"

// Compute negative of an image

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        Image image(argv[1]);

        for (int i = 0; i < image.getHeight(); i++)
        {
            for (int j = 0; j < image.getWidth(); j++)
            {
                image[i][j][0] = 255 - image[i][j][0];
                image[i][j][1] = 255 - image[i][j][1];
                image[i][j][2] = 255 - image[i][j][1];
            }
        }

        image.write(argv[2]);
    }
    else
    {
        std::cerr << "usage: ./negative [input_path] [output_path]" << std::endl;
    }
}
