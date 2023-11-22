#include "tum_rgbd_dataloader.hpp"

#include <vector>
#include <boost/filesystem.hpp>


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
                    std::cerr << "[TumRGBDDataloader] - " << dir << " is not directory";
                    throw std::runtime_error("[TumRGBDDataloader] - " + dir + " is not directory");
                }
                

            }
        }
} // namespace unified_slam::dataloaders