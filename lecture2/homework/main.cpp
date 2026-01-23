#include "tools.hpp"
#include <fmt/core.h>

int main(int argc, char **argv) 
{
    
    cv::Mat src = cv::imread("./img/test_2.jpg");
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