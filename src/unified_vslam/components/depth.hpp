#pragma once

#include <Eigen/Dense>
#include "view.hpp"


namespace unified_slam::components{
    class Depth{
        public:
            Depth(const Eigen::MatrixXd& depth) { depth_ = std::move(depth) ; }
            Depth(const std::string& path);
            void set_depth(const Eigen::MatrixXd& depth) { depth_ = depth; }
            const Eigen::MatrixXd& get_depth() const { return depth_; }
        private:
            Eigen::MatrixXd depth_;
    };
} // namespace unified_slam::component
