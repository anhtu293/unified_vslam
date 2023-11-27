#include "tum_rgbd_dataloader.hpp"
#include "../utils.hpp"

#include <vector>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>


namespace unified_slam::dataloaders{
    unified_slam::dataloaders::TumRGBDDataloader::TumRGBDDataloader(const std::string& dir, std::vector<std::string>& sequences, bool& has_depth, bool& has_pose)
        : has_depth_(has_depth), has_pose_(has_pose) {
            unified_slam::dataloaders::TumRGBDDataloader::BaseDataloader::set_dataset_dir(dir);
            unified_slam::dataloaders::TumRGBDDataloader::BaseDataloader::set_dataset_name("TUM_RGBD");

            sequences_ = std::move(sequences);
            // init sequences_
            if (sequences_.size() == 0){
                boost::filesystem::path ds_path(dir);
                if (!boost::filesystem::is_directory(ds_path))
                {
                    std::cerr << get_dataset_name() << " - " << dir << " is not a directory.";
                    throw std::runtime_error(get_dataset_dir() + " - " + dir + " is not a directory.");
                }
                boost::filesystem::directory_iterator end_itr;
                for (boost::filesystem::directory_iterator itr(ds_path); itr != end_itr; ++itr){
                    std::vector<std::string> tokens = unified_slam::utils::split_string(itr->path().string(), "/");
                    sequences_.push_back(tokens.back());
                }
                std::cout << "[TumRGBDDataloader] - Found " << sequences_.size() << " sequences."; 
            }

            // init items
            std::vector<std::map<std::string, std::string>> items;
            for (auto it = sequences_.begin(); it != sequences_.end(); ++it){
                std::vector<std::string> paths{get_dataset_dir(), *it};
                std::string seq_path_str = unified_slam::utils::join_string(paths, "/");
                boost::filesystem::path seq_path(seq_path_str);
                if (!boost::filesystem::is_directory(seq_path)){
                    std::cerr << get_dataset_name() << " - " << seq_path_str << " is not a directory.";
                    throw std::runtime_error(get_dataset_dir() + " - " + seq_path_str + " is not a directory.");
                }

                // iter cameras (rgb, depth)
                boost::filesystem::directory_iterator end_itr;
                for (boost::filesystem::directory_iterator itr(seq_path); itr != end_itr; ++itr){

                }

                // add pose
                
            }

        }
} // namespace unified_slam::dataloaders