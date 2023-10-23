#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    cv::Mat image;
    image = cv::imread("./samples/test.png", cv::IMREAD_COLOR);
    if (!image.data){
        std::cout << "Could not open file";
        return -1;
    }
    cv::namedWindow("Test", cv::WINDOW_AUTOSIZE);
    cv::imshow("Test", image);
    cv::waitKey(0);
    return 0;
}