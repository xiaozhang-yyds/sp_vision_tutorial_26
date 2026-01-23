#include "tools.hpp"
#include <fmt/core.h>

cv::Mat Scale_image(const cv::Mat& input_image, int output_cols, int output_rows)
{
    cv::Mat output_image;
    double r = std::min(static_cast<double>(output_rows) / input_image.rows,
                        static_cast<double>(output_cols) / input_image.cols);// 计算缩放比例
    int new_cols = static_cast<int>(input_image.cols * r);
    int new_rows = static_cast<int>(input_image.rows * r);
    cv::resize(input_image, output_image, cv::Size(new_cols, new_rows));// 缩放图像

    int dx = (output_cols - new_cols) / 2; // 计算偏移量
    int dy = (output_rows - new_rows) / 2;

    cv::Mat canvas = cv::Mat::zeros(output_rows, output_cols, input_image.type());
    cv::Rect roi(dx, dy, new_cols, new_rows);  // 定义感兴趣区域
    output_image.copyTo(canvas(roi)); // 将缩放后的图像复制到画布上

    fmt::print("Original Image Size: {} * {}\n", input_image.rows, input_image.cols);
    fmt::print("Scaleparams: r = {:.4f}, scaled_size = {}*{}\n",r, canvas.rows, canvas.cols);
    fmt::print("Padding (dx, dy): ({}, {})\n", dx, dy);

    return canvas;
    
    
}
