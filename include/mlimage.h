#ifndef MLIMAGE_H
#define MLIMAGE_H
#include <opencv2/opencv.hpp>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <future>
#include <thread>
#include "feature/ExtractFeatureExecutor.h"

class MlImageProcessor {
public:
    typedef std::unordered_map<std::string, std::unordered_map<std::string, cv::Scalar>> settings_type;
    typedef std::vector<cv::Point> contour_type;

    MlImageProcessor(const std::string&);

    void set_roi(const cv::Mat&);
    std::vector<region_type> extract_feature(const cv::Mat&);
    std::future<std::vector<region_type>> extract_feature_async(const cv::Mat&);
private:
    void load_settings(const std::string&);

    settings_type settings;
    std::unique_ptr<ExtractFeatureExecutor> do_extract_feature;
};

#endif