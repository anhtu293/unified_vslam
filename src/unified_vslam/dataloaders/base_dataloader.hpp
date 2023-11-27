#pragma once

#include <vector>
#include <string>
#include <map>

#include "../components/frame.hpp"

namespace unified_slam::dataloaders{
    class BaseDataloader{
        protected:
            std::vector<std::map<std::string, std::string>> items_; // vector of maps whose keys are `frame`/`left`/`right`, `depth`
            std::string dataset_name_;
            std::string dataset_dir_;

        public:
            BaseDataloader(): dataset_name_("base_dataset"), dataset_dir_("") {}

            int length() const { return items_.size(); }

            // getters
            const std::string& get_dataset_name() const { return dataset_name_; }
            const std::string& get_dataset_dir() const { return dataset_dir_; }

            // setters
            void set_dataset_name(const std::string& dataset_name) { dataset_name_ = dataset_name; }
            void set_dataset_dir(const std::string& dir) { dataset_dir_ = dir; }
            void set_dataset_items(const std::vector<std::map<std::string, std::string>> &items) { items_ = std::move(items); }

            // get item knowing index
            virtual unified_slam::components::Frame get_frame(const int& idx) const = 0;
    };
}
