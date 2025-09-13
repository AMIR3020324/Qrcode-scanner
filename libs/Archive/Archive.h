#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <opencv2/opencv.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

class Archive {
public:
    void save(const cv::Mat& frame, const std::vector<std::string>& data);
};

#endif // ARCHIVE_H