#pragma once

#include <vector>
#include <string>
#include <map>

#include "../components/frame.hpp"

namespace unified_slam::dataloaders{
    class BaseDataloader{
        private:
            std::vector<std::map<std::string, std::string>> items_; // vector of maps whose keys are `frame`, `depth`
            std::string dataset_name_;
            std::string dataset_path_;
            bool has_depth_ = false;
        
        public:
            BaseDataloader(): dataset_name_("base_dataset"), dataset_path_("") {}
            BaseDataloader(const std::string& name, const std::string& dir, const bool& has_depth = false)
                : dataset_name_(name), dataset_path_(dir), has_depth_(has_depth) {}
            int length() const { return items_.size(); }

            // get item knowing index
            virtual unified_slam::components::Frame get_frame(const int& idx) const = 0;
    };
}
