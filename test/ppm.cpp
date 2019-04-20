#include <iostream>
#include <string>
#include "../include/Image.hpp"


int main(int argc, char **argv)
{
    if (argc > 1)
    {
        Image image(argv[1]);

        for (int i =0; i < image.getHeight(); i++)
        {
            for (int j=0; j < image.getWidth(); j++)
            {
                for (int k=0; k < 3; k++)
                {
                    image[i][j][k] = 255 - image[i][j][k];
                }
            }
        }
        
        image.write(argv[2]);
    }
    else
    {
        std::cerr << "usage: ./ppm [input_path] [output_path]" << std::endl;
    }
}