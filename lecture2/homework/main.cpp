#include "tools.hpp"
#include <fmt/core.h>

int main(int argc, char **argv) 
{
    if (argc < 2)
    {
        
        fmt::print("Usage: {} <input_image>\n", argv[0]);
        return 1;
    }
    std::string inPath = argv[1];
    fmt::print("Input image path: {}\n", inPath);
    cv::Mat src = cv::imread(inPath);
    if(src.empty()) 
    {
        fmt::print("Could not open or find the image!\n");
        return -1;
    }
    fmt::print("Image size:{} * {} \n",src.rows,src.cols);
    cv::imshow("Scaled Image", Scale_image(src,640,640));
    cv::waitKey(0);
    return 0;
}