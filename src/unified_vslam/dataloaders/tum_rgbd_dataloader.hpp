#pragma once

#include "base_dataloader.hpp"
#include "../components/frame.hpp"
#include <vector>
#include <map>

namespace unified_slam::dataloaders{
    class TumRGBDDataloader: public unified_slam::dataloaders::BaseDataloader {
        private:
            std::vector<std::string> sequences_;
            bool has_pose_;
            bool has_depth_;
        
        public:
            TumRGBDDataloader(const std::string& dir, std::vector<std::string>& sequences, bool& has_depth, bool& has_pose);
            unified_slam::components::Frame get_frame(const int& idx);
    };
} // namespace unified_slam::dataloaders