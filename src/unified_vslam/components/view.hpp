#pragma once

#include <opencv2/opencv.hpp>

namespace unified_slam::components{
    class View{
        public:
            View(const cv::Mat& image) { image_ = image; }
            const cv::Mat& image() const { return image_; }
            void image(const cv::Mat& image) { image_ = image; }
            void render(const std::string& name);
        public:
            cv::Mat image_;
    }
} // namespace unified_slam::components
