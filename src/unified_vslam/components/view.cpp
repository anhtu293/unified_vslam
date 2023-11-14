#include  "view.hpp"

namespace unified_slam::components{
    void View::render(const std::string& name){
        cv::namedWindow("Frame", cv::WINDOW_AUTOSIZE);
        cv::imshow(name, image_);
        cv::waitKey();
    }
} // namespace unified_slam::components
