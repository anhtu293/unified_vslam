#include "frame.hpp"


namespace unified_slam::components{
    Frame::Frame(const std::string& path){
        cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
        if (!image.data){
            std::cerr << "Could not open file at path" << path;
            throw std::runtime_error("Could not open file at path: " + path);
        }
        image_ = std::move(image);
    }

    Frame::Frame(const cv::Mat& image){
        image_ = std::move(image);
    }
} // namespace unified_slam::components
