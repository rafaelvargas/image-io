#include <string>
#include <iostream>
#include "../include/Image.hpp"

// Creates a pixelmap and assigns colors to pixels.

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        Image image(100, 100);

        for (int i = 0; i < image.getHeight(); i++)
        {
            for (int j = 0; j < image.getWidth(); j++)
            {
                image[i][j][0] = 255;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
        }

        image.write(argv[1]);
    }
    else
    {
        std::cerr << "usage: ./image-creation [input_path] [output_path]" << std::endl;
    }
}
