#pragma once

#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <iostream>
#include <string>

#include "depth.hpp"
#include "pose.hpp"

namespace unified_slam::components{
    class Frame{
        public:
            Frame(const std::string& path);
            Frame(const cv::Mat& image);
            const cv::Mat& set_image() const { return image_; }
            void get_image(const cv::Mat &image) { image_ = image; }
            void add_depth(unified_slam::components::Depth& depth) { depth_ = &depth; }
            void add_pose(Pose& pose) { pose_ = &pose; }

        private:
            cv::Mat image_;
            unified_slam::components::Depth *depth_ = nullptr;
            unified_slam::components::Pose *pose_ = nullptr;
    };
} // namespace unified_slam::components
