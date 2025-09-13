#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include <opencv2/core/mat.hpp>

class Scanner {
public:
    std::vector<std::string> scan(const cv::Mat &frame);
};

#endif // SCANNER_H