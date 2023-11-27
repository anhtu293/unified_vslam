#pragma once

#include <dirent.h>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>


namespace unified_slam::utils{
    std::vector<std::string> split_string(const std::string& str, const std::string delimiter){
        std::vector<std::string> tokens;
        boost::algorithm::split(tokens, str, boost::is_any_of(delimiter));
        return tokens;
    }

    std::string join_string(const std::vector<std::string>& tokens, const std::string delimiter){
        std::string joined_str = boost::algorithm::join(tokens, delimiter);
        return joined_str;
    }

} // namespace unified_slam::utils